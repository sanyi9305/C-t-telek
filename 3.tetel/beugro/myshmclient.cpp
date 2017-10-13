/**
 * @brief Justine - this is a rapid prototype for development of Robocar City Emulator
 *
 * @file myshmclient.cpp
 * @author  Norbert Bátfai <nbatfai@gmail.com>
 * @version 0.0.10
 *
 * @section LICENSE
 *
 * Copyright (C) 2014 Norbert Bátfai, batfai.norbert@inf.unideb.hu
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * @section DESCRIPTION
 * Robocar City Emulator and Robocar World Championship
 *
 * desc
 *
 */

#include <algorithm>
#include <myshmclient.hpp>
#include <limits>
//#include <trafficlexer.hpp>

char data[524288];

std::vector<justine::sampleclient::MyShmClient::Gangster> justine::sampleclient::MyShmClient::gangsters ( boost::asio::ip::tcp::socket & socket, int id,
    osmium::unsigned_object_id_type cop )
{

  boost::system::error_code err;

  size_t length = std::sprintf ( data, "<gangsters " );
  length += std::sprintf ( data+length, "%d>", id );

  socket.send ( boost::asio::buffer ( data, length ) );

  length = socket.read_some ( boost::asio::buffer ( data ), err );

  if ( err == boost::asio::error::eof )
    {

      // TODO

    }
  else if ( err )
    {

      throw boost::system::system_error ( err );
    }

  /* reading all gangsters into a vector */
  int idd {0};
  unsigned f, t, s;
  int n {0};
  int nn {0};
  std::vector<Gangster> gangsters;

  while ( std::sscanf ( data+nn, "<OK %d %u %u %u>%n", &idd, &f, &t, &s, &n ) == 4 )
    {
      nn += n;
      gangsters.push_back ( Gangster {idd, f, t, s} );
    }

  std::sort ( gangsters.begin(), gangsters.end(), [this, cop] ( Gangster x, Gangster y )
  {
    return dst ( cop, x.to ) < dst ( cop, y.to );
  } );

  //std::cout.write ( data, length );
  //std::cout << "Command GANGSTER sent." << std::endl;

  return gangsters;
}

std::vector<justine::sampleclient::MyShmClient::Cop> justine::sampleclient::MyShmClient::initcops ( boost::asio::ip::tcp::socket & socket )
{

  boost::system::error_code err;

  size_t length = std::sprintf ( data, "<init guided %s 10 c>", m_teamname.c_str() );

  socket.send ( boost::asio::buffer ( data, length ) );

  length = socket.read_some ( boost::asio::buffer ( data ), err );


  if ( err == boost::asio::error::eof )
    {

      // TODO

    }
  else if ( err )
    {

      throw boost::system::system_error ( err );
    }

  /* reading all gangsters into a vector */
  int idd {0};
  int f, t;
  char c;
  int n {0};
  int nn {0};
  std::vector<Cop> cops;

  while ( std::sscanf ( data+nn, "<OK %d %d/%d %c>%n", &idd, &f, &t, &c, &n ) == 4 )
    {
      nn += n;
      cops.push_back ( idd );
    }

  //std::cout.write ( data, length );
  //std::cout << "Command INIT sent." << std::endl;

  return cops;
}


int justine::sampleclient::MyShmClient::init ( boost::asio::ip::tcp::socket & socket )
{

  boost::system::error_code err;

  size_t length = std::sprintf ( data, "<init guided %s 1 c>", m_teamname.c_str() );

  socket.send ( boost::asio::buffer ( data, length ) );

  length = socket.read_some ( boost::asio::buffer ( data ), err );

  if ( err == boost::asio::error::eof )
    {

      // TODO

    }
  else if ( err )
    {

      throw boost::system::system_error ( err );

    }

  int id {0};
  std::sscanf ( data, "<OK %d", &id );

  //std::cout.write ( data, length );
  //std::cout << "Command INIT sent." << std::endl;

  return id;

}

void justine::sampleclient::MyShmClient::pos ( boost::asio::ip::tcp::socket & socket, int id )
{

  boost::system::error_code err;

  size_t length = std::sprintf ( data, "<pos " );
  length += std::sprintf ( data+length, "%d %u %u>", id, 2969934868u, 651365957u );

  socket.send ( boost::asio::buffer ( data, length ) );

  length = socket.read_some ( boost::asio::buffer ( data ), err );

  if ( err == boost::asio::error::eof )
    {

      // TODO

    }
  else if ( err )
    {

      throw boost::system::system_error ( err );

    }

  std::cout.write ( data, length );
  std::cout << "Command POS sent." << std::endl;
}

void justine::sampleclient::MyShmClient::car ( boost::asio::ip::tcp::socket & socket, int id, unsigned *f, unsigned *t, unsigned* s )
{

  boost::system::error_code err;

  size_t length = std::sprintf ( data, "<car " );
  length += std::sprintf ( data+length, "%d>", id );

  socket.send ( boost::asio::buffer ( data, length ) );

  length = socket.read_some ( boost::asio::buffer ( data ), err );

  if ( err == boost::asio::error::eof )
    {

      // TODO

    }
  else if ( err )
    {

      throw boost::system::system_error ( err );
    }

  int idd {0};
  std::sscanf ( data, "<OK %d %u %u %u", &idd, f, t, s );

  //std::cout.write ( data, length );
  //std::cout << "Command CAR sent." << std::endl;

}

void justine::sampleclient::MyShmClient::route (
  boost::asio::ip::tcp::socket & socket,
  int id,
  std::vector<osmium::unsigned_object_id_type> & path
)
{

  boost::system::error_code err;

  size_t length = std::sprintf ( data,
                                 "<route %d %d", path.size(), id );

  for ( auto ui: path )
    length += std::sprintf ( data+length, " %u", ui );

  length += std::sprintf ( data+length, ">" );

  socket.send ( boost::asio::buffer ( data, length ) );

  length = socket.read_some ( boost::asio::buffer ( data ), err );

  if ( err == boost::asio::error::eof )
    {

      // TODO

    }
  else if ( err )
    {

      throw boost::system::system_error ( err );

    }

  //std::cout.write ( data, length );
  //std::cout << "Command ROUTE sent." << std::endl;

}

void justine::sampleclient::MyShmClient::start ( boost::asio::io_service& io_service, const char * port )
{

#ifdef DEBUG
  foo();
#endif

  boost::asio::ip::tcp::resolver resolver ( io_service );
  boost::asio::ip::tcp::resolver::query query ( boost::asio::ip::tcp::v4(), "localhost", port );
  boost::asio::ip::tcp::resolver::iterator iterator = resolver.resolve ( query );

  boost::asio::ip::tcp::socket socket ( io_service );
  boost::asio::connect ( socket, iterator );

  int id = init ( socket );

  pos ( socket, id );

  unsigned int g {0u};
  unsigned int f {0u};
  unsigned int t {0u};
  unsigned int s {0u};

  std::vector<Gangster> gngstrs;

  for ( ;; )
    {
      std::this_thread::sleep_for ( std::chrono::milliseconds ( 200 ) );

      car ( socket, id, &f, &t, &s );

      gngstrs = gangsters ( socket, id, t );

      if ( gngstrs.size() > 0 )
        g = gngstrs[0].to;
      else
        g = 0;
      if ( g > 0 )
        {

          std::vector<osmium::unsigned_object_id_type> path = hasDijkstraPath ( t, g );

          if ( path.size() > 1 )
            {

              std::copy ( path.begin(), path.end(),
                          std::ostream_iterator<osmium::unsigned_object_id_type> ( std::cout, " -> " ) );

              route ( socket, id, path );
            }
        }
    }
}

void justine::sampleclient::MyShmClient::start10 ( boost::asio::io_service& io_service, const char * port )
{

#ifdef DEBUG
  foo();
#endif

  boost::asio::ip::tcp::resolver resolver ( io_service );
  boost::asio::ip::tcp::resolver::query query ( boost::asio::ip::tcp::v4(), "localhost", port );
  boost::asio::ip::tcp::resolver::iterator iterator = resolver.resolve ( query );

  boost::asio::ip::tcp::socket socket ( io_service );
  boost::asio::connect ( socket, iterator );

  std::vector<Cop> cops = initcops ( socket );

  // annak a gengszternek az to-ja, akit minden rendőr üldözni fog
  unsigned int chased_gangster_to {0u};

  // annak a gengszternek az id-ja, akit minden rendőr üldözni fog
  unsigned int chased_gangster_id {0u};

  // aktuális rendőr to-ja (eredetileg t)
  unsigned int cop_to {0u};

  // a mminimumkiválasztó algoritmushoz kell
  // ebben fogjuk tárolni, hogy aktuálisan melyik a legeslegközelebbi gengszter
  // távolsága
  double cop_gangster_min_dst;

  // megadja, hogy követünk-e valakit éppen
  // ha false, akkor nem követünk senkit, tehát
  // keresnünk kell egy új gengsztert
  bool is_chasing = false;

  unsigned int g {0u};
  unsigned int g_id {0u};
  unsigned int f {0u};
  unsigned int t {0u};
  unsigned int s {0u};

  std::vector<Gangster> gngstrs;

  for ( ;; )
  {
    std::this_thread::sleep_for ( std::chrono::milliseconds ( 200 ) );

    // ha nem üldözünk senkit (vagy most indultunk, vagy elkaptunk valakit)
    // akkor megpróbálunk keresni valakit
    if (!is_chasing)
    {
      // a legkisebb távolságot beállítjuk a double-ban tárolható
      // legnagyobb értékre, tehát biztosan fogunk ennél kisebbet
      // találni -> lesz üldözhető gengszter
      cop_gangster_min_dst = std::numeric_limits<double>::max();

      // beállítjuk, hogy van kit üldöznünk
      // azonban, ha 0 gengszter van, akkor nyilván nincs
      // de itt még arról nem tudunk, hogy 0 van
      is_chasing = true;

      // a rendőrökhöz legközelebbi gengszterek közül kell a legkisebb távolságút
      // üldöznünk
      // ehhez minden rendőrhöz meg kell keresnünk a legközelebb esőt
      // és ezek között egy minimumkiválasztást csinálni
      // szerencsére egy ciklusban megtehetjük
      for (auto cop:cops)
      {
        // lekérdezzük a rendőrünk helyét
        car (socket, cop, &f, &cop_to, &s);

        // gngstrs távolság szerint npvekvő sorrendben tartalmazza
        // a gengsztereket, szóval nekünk az 1. (0.) elem fog kelleni
        gngstrs = gangsters (socket, cop, cop_to);

        // mivel most már lekérdeztük a gengsztereket, tudjuk, hogy hány van
        // ha nincs egysem, akkor mégsem üldözünk senkit.
        // nem is keresünk tovább, BREAK
        if (gngstrs.size() == 0)
        {
          is_chasing = false;
          break;
        }

        // a dst(csomópont, csomópont) kiszánolja két csomópont távolságát
        // ezt fogjuk felhasználni, hogy meghatározzuk az egyes rendőrök
        // ls a hozzájuk legközelebb eső gengszterek távolságát
        if (dst(cop_to, gngstrs[0].to) < cop_gangster_min_dst)
        {
          // az id-t eltároljuk, hogy ha még útközben esetleg lesz is, aki közelebb
          // esne valamelyik rendőrhöz, biztos erre menjünk,
          // illetve ennek segítségével fogjuk megkeresni a megfelelő to értéket
          chased_gangster_id = gngstrs[0].id;

          chased_gangster_to = gngstrs[0].to;

          // új minimum
          cop_gangster_min_dst = dst(cop_to, gngstrs[0].to);
        }
      }
      // a ciklus után megvan a megfelelő gengszter
    }
    else
    {
      // ide akkor lépünk be, ha is_chasing értéke igaz
      // az is_chasing akkor is igaz marad, ha a gengszter, akit követünk,
      // el lett kapva, tehát figyelnünk kell, hogy a chased_gangster_id-val
      // rendelkező gengszter ott van-e még a gengszterek között

      // ha már itt vagyunk (mivel ezt mindig megcsináljuk), egyúttal a to-t
      // is meg tudjuk határozni, így azt a következő for ciklusban nem kell

      // lekérjük a gengsztereket, hogy megnézzük benne van-e még
      // az az id, amit mi üldözünk
      // teljesen mindegy, melyik rendőrhöz képest rendezzük a gengsztereket
      // szóval az első rendőr ideális lesz
      gngstrs = gangsters (socket, cops[0], cop_to);

      // lambdát használunk, illetve az <algorithm>-ben található
      // find_if-et
      // a find_if adott feltétel mellett visszaadja a keresett elemet
      // egyébként jelen esetben a gngstrs.end()-et adja vissza
      // Ebben az esetben új célpontot kell keresnünk
      std::vector<Gangster>::iterator it =
        std::find_if(gngstrs.begin(), gngstrs.end(),
          // a chased_gangster_id-t odaadjuk a lambdának
          // a lambda paramétere a vektor egy eleme, amihez éppen hasonlít
          [chased_gangster_id](Gangster element)
          {
            // bool-t kell visszaadnunk
            // akkor van találat, ha a vektor aktuális elemének id-je
            // megegyezik az üldözöttünk id-jával
            return element.id == chased_gangster_id;
          });
      // ha it az intervallum vége, akkor az éppen üldözött gengszter már nincsen
      // benne a gngstrs vektorban, tehát el lett kapva.
      if (it == gngstrs.end())
      {
        // false, szóval a következő ciklus iterációban új célpontot keresünk majd
        is_chasing = false;
      }
      else
      {
        // egyébként, ha már úgyis megtaláltuk ezt a gengsztert, tároljuk is
        // el a pozícióját, szóval a következő ciklusban, ami a route-olással foglalkozik
        // nem kell újra előszednünk
        chased_gangster_to = it->to;
      }
    }

    // kiírjuk, hogy kit üldözünk (ha egyáltalán üldözünk valakit)
    if (!is_chasing)
      std::cout << "There's no gangster to chase!" << std::endl;
    else
      std::cout << "Chasing: ID# " << chased_gangster_id << std::endl;

    for ( auto cop:cops )
    {
      // csak akkor adunk utasítást a kocsiknak, hogy menjenek valahova
      // ha van kit követni, tehát az is_chasing értéke true
      if (is_chasing)
      {
        car ( socket, cop, &f, &cop_to, &s );

        // minden rendőrnek megmondjuk hogy az aktiális pozíciójától induljon
        // és a közös gengszterhez menjen.
        // a közös gengszter to-ja a chased_gangster_to
        std::vector<osmium::unsigned_object_id_type> path =
          hasDijkstraPath (cop_to, chased_gangster_to);

        if ( path.size() > 1 )
        {
          //std::copy ( path.begin(), path.end(),
          //            std::ostream_iterator<osmium::unsigned_object_id_type> ( std::cout, " -> " ) );

          route ( socket, cop, path );
        }
      }
    }
  }
}

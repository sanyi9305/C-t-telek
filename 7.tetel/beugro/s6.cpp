/*
 * Poszt feladatok: válassz ki a source/binom/Batfai-Barki/lambda/s?.cpp fájlok közül hármat
 * és hasonlítsd össze őket egy mesélős posztban a linkedin-en. (A forrásokat ne tedd be, csak
 * jelezd, hogy melyikről van szó; én mepróbáltam, nem jött be:
 *
 * - https://www.linkedin.com/groups/Folyos%C3%B3i-besz%C3%A9lget%C3%A9sek-mire-j%C3%B3-lambda-7446358.S.5840580176529879041?trk=groups_search_item_list-0-b-ttl&goback=.gna_7446358
 * - https://www.linkedin.com/groups/Folyos%C3%B3i-besz%C3%A9lget%C3%A9sek-mire-j%C3%B3-lambda-7446358.S.5840578655805280259?trk=groups_search_item_list-0-b-ttl&goback=.gna_7446358
 *
 * Az első 10 hallgató számolhat el 15 pontot, aki felteszi a posztot, majd május 20-án megnézzők,
 * hogy melyik szakmai poszt kapta a legtöbb lájkot, s a győztes további 15 pontot számolhat el.
 */

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <boost/lambda/lambda.hpp>

bool comp(const int &a, const int &b)
{
    return a < b;
}

int main()
{
    std::vector<int> v;

    v.push_back(4);
    v.push_back(5);
    v.push_back(3);

    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, ", "));

    std::cout << std::endl;

    std::sort(v.begin(), v.end(), boost::lambda::ret<bool>(boost::lambda::_2 < boost::lambda::_1));

    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, ", "));

    std::cout << std::endl;

    return 0;
}

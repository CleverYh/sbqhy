#ifndef __WORDLADDER_H__
#define __WORDLADDER_H__
/*
    Reference to textbook P143
 */
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

map<string, vector<string>> computeAdjacentWords_cyh(const vector<string> &words) {
    map<string, vector<string>> adjWords;
    map<int, vector<string>> wordsByLength;
    for (auto &str : words) wordsByLength[str.length()].push_back(str); // 按单词长度分组
    for (auto &entry : wordsByLength) {
        const vector<string> &groupsWords = entry.second;
        int groupNum = entry.first; // 单词长度

        for (int i = 0; i < groupNum; i++) { // 遍历单词上的每一个位置
            map<string, vector<string>> repToWord;
            for (auto &str : groupsWords) {
                string rep = str;
                rep.erase(i, 1);               // 删去i位上的字母
                repToWord[rep].push_back(str); // 一组单词与代表
            }

            for (auto &entry : repToWord) {                  // building the map
                const vector<string> &clique = entry.second; //clique n.派系; 私党; 小集团; 小圈子;
                if (clique.size() >= 2) {
                    for (int i = 0; i < clique.size(); i++) {
                        for (int j = i + 1; j < clique.size(); j++) {
                            adjWords[clique[i]].push_back(clique[j]);
                            adjWords[clique[j]].push_back(clique[i]);
                        }
                    }
                }
            }
        }
    }
    return adjWords;
}

vector<string> adjacentWords(const vector<string> &dict, string word) {

    map<string, vector<string>> adjacentWords;
    adjacentWords = computeAdjacentWords_cyh(dict);

    vector<string> ladder;
    ladder.push_back(word);
    for (string &word : adjacentWords[word]) {
        ladder.push_back(word);
    }

    sort(ladder.begin(), ladder.end());

    return ladder;
}

#endif /* __WORDLADDER_H__ */

#if 0
以后仔细找error，尽量不写warning。（这种 comparison of integer expressions of different signedness 其实可以不管它）
In file included from testWordLadder.cpp:9:
WordLadder.h: In function 'std::map<std::__cxx11::basic_string<char>, std::vector<std::__cxx11::basic_string<char> > > computeAdjacentWords(const std::vector<std::__cxx11::basic_string<char> >&)':
WordLadder.h:33:39: warning: comparison of integer expressions of different signedness: 'int' and 'std::vector<std::__cxx11::basic_string<char> >::size_type' {aka 'long unsigned int'} [-Wsign-compare]
   33 |                     for (int i = 0; i < clique.size(); i++) {
      |                                     ~~^~~~~~~~~~~~~~~
WordLadder.h:34:47: warning: comparison of integer expressions of different signedness: 'int' and 'std::vector<std::__cxx11::basic_string<char> >::size_type' {aka 'long unsigned int'} [-Wsign-compare]
   34 |                         for (int j = i + 1; j < clique.size(); j++) {
      |                                             ~~^~~~~~~~~~~~~~~
testWordLadder.cpp: In function 'bool oneCharOff(const string&, const string&)':
testWordLadder.cpp:60:23: warning: comparison of integer expressions of different signedness: 'int' and 'std::__cxx11::basic_string<char>::size_type' {aka 'long unsigned int'} [-Wsign-compare]
   60 |     for( int i = 0; i < word1.length( ); ++i )
      |                     ~~^~~~~~~~~~~~~~~~~
testWordLadder.cpp: In function 'std::map<std::__cxx11::basic_string<char>, std::vector<std::__cxx11::basic_string<char> > > computeAdjacentWordsSlow(const std::vector<std::__cxx11::basic_string<char> >&)':
testWordLadder.cpp:76:23: warning: comparison of integer expressions of different signedness: 'int' and 'std::vector<std::__cxx11::basic_string<char> >::size_type' {aka 'long unsigned int'} [-Wsign-compare]
   76 |     for( int i = 0; i < words.size( ); ++i )
      |                     ~~^~~~~~~~~~~~~~~
testWordLadder.cpp:77:31: warning: comparison of integer expressions of different signedness: 'int' and 'std::vector<std::__cxx11::basic_string<char> >::size_type' {aka 'long unsigned int'} [-Wsign-compare]
   77 |         for( int j = i + 1; j < words.size( ); ++j )
      |                             ~~^~~~~~~~~~~~~~~
testWordLadder.cpp: In function 'std::map<std::__cxx11::basic_string<char>, std::vector<std::__cxx11::basic_string<char> > > computeAdjacentWordsMedium(const std::vector<std::__cxx11::basic_string<char> >&)':
testWordLadder.cpp:107:27: warning: comparison of integer expressions of different signedness: 'int' and 'std::vector<std::__cxx11::basic_string<char> >::size_type' {aka 'long unsigned int'} [-Wsign-compare]
  107 |         for( int i = 0; i < groupsWords.size( ); ++i )
      |                         ~~^~~~~~~~~~~~~~~~~~~~~
testWordLadder.cpp:108:35: warning: comparison of integer expressions of different signedness: 'int' and 'std::vector<std::__cxx11::basic_string<char> >::size_type' {aka 'long unsigned int'} [-Wsign-compare]
  108 |             for( int j = i + 1; j < groupsWords.size( ); ++j )
      |                                 ~~^~~~~~~~~~~~~~~~~~~~~
testWordLadder.cpp: At global scope:
testWordLadder.cpp:124:1: error: redefinition of 'std::map<std::__cxx11::basic_string<char>, std::vector<std::__cxx11::basic_string<char> > > computeAdjacentWords(const std::vector<std::__cxx11::basic_string<char> >&)'
  124 | computeAdjacentWords( const vector<string> & words )
      | ^~~~~~~~~~~~~~~~~~~~
In file included from testWordLadder.cpp:9:
WordLadder.h:14:29: note: 'std::map<std::__cxx11::basic_string<char>, std::vector<std::__cxx11::basic_string<char> > > computeAdjacentWords(const std::vector<std::__cxx11::basic_string<char> >&)' previously defined here
   14 | map<string, vector<string>> computeAdjacentWords(const vector<string> &words) {
      |                             ^~~~~~~~~~~~~~~~~~~~
testWordLadder.cpp: In function 'std::map<std::__cxx11::basic_string<char>, std::vector<std::__cxx11::basic_string<char> > > computeAdjacentWords(const std::vector<std::__cxx11::basic_string<char> >&)':
testWordLadder.cpp:159:39: warning: comparison of integer expressions of different signedness: 'int' and 'std::vector<std::__cxx11::basic_string<char> >::size_type' {aka 'long unsigned int'} [-Wsign-compare]
  159 |                     for( int p = 0; p < clique.size( ); ++p )
      |                                     ~~^~~~~~~~~~~~~~~~
testWordLadder.cpp:160:47: warning: comparison of integer expressions of different signedness: 'int' and 'std::vector<std::__cxx11::basic_string<char> >::size_type' {aka 'long unsigned int'} [-Wsign-compare]
  160 |                         for( int q = p + 1; q < clique.size( ); ++q )
      |                                             ~~^~~~~~~~~~~~~~~~
testWordLadder.cpp: In function 'bool comp(const std::vector<std::__cxx11::basic_string<char> >&, const std::vector<std::__cxx11::basic_string<char> >&)':
testWordLadder.cpp:198:17: warning: comparison of integer expressions of different signedness: 'int' and 'std::vector<std::__cxx11::basic_string<char> >::size_type' {aka 'long unsigned int'} [-Wsign-compare]
  198 |   for (int i=0;i<u.size();i++)
      |                ~^~~~~~~~~
testWordLadder.cpp: In function 'int main()':
testWordLadder.cpp:216:15: warning: comparison of integer expressions of different signedness: 'int' and 'std::vector<std::__cxx11::basic_string<char> >::size_type' {aka 'long unsigned int'} [-Wsign-compare]
  216 | for (int i=0;i<ws.size();i++) {
      |              ~^~~~~~~~~~
testWordLadder.cpp:205:20: warning: unused variable 'end' [-Wunused-variable]
  205 |     clock_t start, end;
      |                    ^~~

#endif

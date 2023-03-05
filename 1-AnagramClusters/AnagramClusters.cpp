/*
 * File: AnagramClusters.cpp
 * --------------------
 * Name: [TODO: enter name here]
 * This file is the starter project for the Anagram Clusters problem
 * on Assignment #2.
 * [TODO: extend the documentation]
 */
//-*- 苟利国家生死以，岂因祸福避趋之。——林则徐 -*-
#include <iostream>
#include <string>
#include "console.h"
#include "lexicon.h"
#include "simpio.h"
#include "strlib.h"
#include "map.h"
using namespace std;

/* Function prototypes */

string sortedVersionOf(const string& input);

/* Main program */

int main()
{
    Lexicon english("EnglishWords.txt");

    Map<string, Lexicon> anagramClusters;

    /* Distribute words into their anagram clusters by using
     * the handy map autoinsertion feature.
     * [TODO: fill the code]
     */
    for(string str : english){
        anagramClusters[sortedVersionOf(toLowerCase(str))].add(str);   //根据函数返回结果，构造键值对；
    }

    while (true) {
        string word = getLine("Enter a word: ");

        /* The key we'll use will be the sorted version of the word.
         * Question to ponder: why convert to lower case, then
         * sort, rather than the other way around?
         */
        string key = sortedVersionOf(toLowerCase(word));
        if (word =="") break;                               //添加退出条件
        if (anagramClusters.containsKey(key)) {
            cout << anagramClusters[key] << endl;
        } else {
            cout << "Opps, such words are not to be found here!" << endl;
        }
    }
    return 0;
}


/**
 * Given a word, returns a string formed by sorting the letters
 * in that word.
 *
 * @param word The input word
 * @return A sorted version of the word
 */
string sortedVersionOf(const string& input) {
    /* This algorithm is an implementation of an algorithm called
     * "Counting Sort." It's described in the slides 05 for Lecture.
     */

    /* Build a frequency table of the letters in the word.
     * [TODO: fill the code]
     */
    Map<char,int> LetterTable;
    for(char ch : input)        //遍历字符串，统计每个字母个数
    {
        LetterTable[ch] ++;
    }
    string result;
    /* Iterate over the frequency table and build the result
     * string from the information it contains.
     * [TODO: fill the code]
     */
    for(char key : LetterTable)         //根据映射的键与对应的出现次数构造新的字符串，用于标识单词
    {
        for(int i =0;i<LetterTable[key];i++){
            result+=key;
        }
    }
    return result;

}




























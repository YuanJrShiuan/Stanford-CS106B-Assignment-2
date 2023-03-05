/*
 * File: WordLadder.cpp
 * --------------------
 * Name: [TODO: enter name here]
 * This file is the starter project for the word ladder problem
 * on Assignment #2.
 * [TODO: extend the documentation]
 */
/*
 * 相信奇迹的人本身就和奇迹一样了不起。——麦当
*/
#include "lexicon.h"
#include "queue.h"
#include "simpio.h"
#include "vector.h"
#include "console.h"
#include "map.h"
#include <iostream>
using namespace std;
void final(Vector<string>& ladder);  //输出程序
void WordLabber(string a,string b,Lexicon& wordlist);  //主程序
int main() {
    while(true){
    string firstword = getLine("Enter start word(return to quit):");
    if(firstword == "") break;  //退出检验
    string endword = getLine("Enter destination word:");
    Lexicon wordlist("EnglishWords.txt");
    WordLabber(firstword,endword,wordlist);
    cout << endl;
    }
    return 0;
}
void final(Vector<string>& ladder){
    cout << "Found ladder:";
    for(string str:ladder){
        cout << str << " ";
    }
}
void WordLabber(string a,string b,Lexicon& wordlist){
    if(!wordlist.contains(a) || !wordlist.contains(b)){  //输入合法性检验
        cout << "Invaild input!" << endl;
        return;
    }
    Vector<string> p;    //第一个向量，用来初始化
    p.add(a);
    Queue<string> q;     //单词迭代队列，用于BFS
    Queue<Vector<string>> labber;  //嵌套队列，用于标识每次的labber
    labber.enqueue(p);
    q.enqueue(a);
    wordlist.remove(a);
    while(!q.isEmpty()){
        string header = q.dequeue();
        Vector<string> ThisLabber = labber.dequeue();
        if(ThisLabber[ThisLabber.size()-1] == b){
            final(ThisLabber);
            return;
        }
        int n = header.size();
        for(int i =0;i<n;i++){
            for(char ch = 'a'; ch < 'z';ch++){
                string next = header;
                next[i] = ch;
                if(wordlist.contains(next)){
                    q.enqueue(next);
                    wordlist.remove(next);
                    Vector<string> p1 = ThisLabber;
                    p1.add(next);
                    labber.enqueue(p1);
                }
            }
        }
    }
    cout << "No answers!";
    return;
}

/*
 * File: AreaCodes.cpp
 * --------------------
 * Name: [TODO: enter name here]
 * This file is the starter project for the Area Codes problem
 * on Assignment #2.
 * [TODO: extend the documentation]
 */

#include <iostream>
#include <cctype>
#include <fstream>
#include <string>
#include "error.h"
#include "map.h"
#include "simpio.h"
#include "strlib.h"
#include "console.h"
#include "vector.h"
using namespace std;

/* Function prototypes */

void readCodeFile(string filename, Map<int,string> & map);
void invertStoA(const Map<int,string>& map1,Map<string,Vector<int>>& map2);
/* Main program */

int main()
{
   Map<int,string> areaCodeToState;
   readCodeFile("AreaCodes.txt", areaCodeToState);
   Map<string,Vector<int>> StateToAreaCode;
   invertStoA(areaCodeToState,StateToAreaCode);
 /*
 * The program looks up a numeric area codes for the United States
 * and Canada,works in both directions.  If the user enters a number,
 * the program prints out the state or province to which that code is
 * assigned. If the user enters a name, it prints out all the area
 * codes assigned to that name.
 * TODO fill the code.
 */
   while(true){
       string tmp;
       tmp = getLine("Enter area code or state name:");
       if(tmp == "") {                                  //空输入结束循环
           cout << "No input!Done!" << endl;
           break;
       }
       bool flag;                                   //判断输入类型
       for(char ch : tmp){
           if(isdigit(ch)) flag = true;
           else flag = false;
       }
       if(flag == true) cout << areaCodeToState[stringToInteger(tmp)] << endl;
       else cout << StateToAreaCode[tmp] << endl;

   }


   return 0;
}

/*
 * Function: readCodeFile
 * Usage: readCodeFile(filename, map);
 * -----------------------------------
 * Reads a data file representing area codes and locations into the map,
 * which must be declared by the client.  Each line must consist of the
 * area code, a hyphen, and the name of the state/province.
 */

void readCodeFile(string filename, Map<int,string>& map)
{
   ifstream infile;

   infile.open(filename.c_str());
   if (infile.fail())
       error("Can't read the data file");

   string line;
   while (getline(infile, line))
   {

    /* The program parses the every line of Area Codes file,
     * inserts the pairs, (area code, the name of the state/province)
     * into the map.
     * TODO fill the code
    */
    string num = "",state = "";
    for(char ch : line){                    //分别读入行中的数字和城市名
        if(isdigit(ch)) num+=ch;
        else if(isalpha(ch) || isspace(ch)) state+=ch;
        else continue;
    }
    int t = stringToInteger(num);           //存入映射
    map[t] = state;
   }

   infile.close();

}
void invertStoA(const Map<int,string>& map1,Map<string,Vector<int>>& map2){
    for(int n : map1){                  //将map1键值对兑换位置存入新的映射
        map2[map1[n]]+= n;
    }
}

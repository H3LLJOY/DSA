//#include <cmath>
//#include <cstdio>
//#include <vector>
//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//
//bool isOperator(char c){
//    if( c=='+' || c=='-' || c=='*' || c=='%' || c=='@' ){
//        return true;
//    }
//    return false;
//}
//
//bool hasNoNumericalNumbers(string str) {
//    for (char ch : str) {
//        if (isdigit(ch)) {
//            return false;  // Found a numerical digit
//        }
//    }
//    return true;  // No numerical digits found
//}
//
//bool isValid(string expression) {
//    if (hasNoNumericalNumbers(expression) || isOperator(expression[size (expression)-1 ]) ) //expression eke anthima char eka operator ekaknm false wennepai (2-2-2)@
//        return false;
//
//    else if(expression[0]=='0') return false;
//
//    for (int i = 0; i < expression.size() - 1; i++) {
//        if (isOperator(expression[i]) && isOperator(expression[i + 1])) {
//            return false;
//        }
//        else if(  isdigit(expression[i]) && expression[i+1]== '(' ){
//            return false;
//        }
//        else if( isOperator(expression[i]) && expression[i+1] == '0' ){
//            return false;
//        }
//    }
//    return true;
//}
//
//
//int evaluator(string expression){
//      if (expression.size()==1) return stoi(expression);
////
////    int bracketPosition = expression.find('(');
////    if (bracketPosition!= string::npos){
////        return bracketPosition;
////    }
//      int minOperator=expression.find('%');
//      int maxOperator=expression.find('@');
//
//
//
//
//
//    return -1;
//}
//
//
//void expressionEvaluator(vector<string> expressions){
//    for(const string& expression : expressions){
//        if ( ! isValid(expression) ) {
//            cout << "invalid" << endl;
//        }
//        else
//            cout<<evaluator(expression)<<endl;
//    }
//}
//
//
//int main() {
//    int n; //number of expressions
//    cin>>n;
//    cin.ignore();
//
//    string line; //to store an input line
//
//    vector<string> expressions;
//
//    for(int i=0 ; i<n ;i++){
//        cin>>line;
//        expressions.push_back(line);
//    }
//
//    expressionEvaluator(expressions);
//
//
////    for(string str:expressions){
////        cout<<str<<endl;
////    }
//
//
//    return 0;
//}

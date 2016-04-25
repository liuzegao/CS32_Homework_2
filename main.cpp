//
//  main.cpp
//  CS32_Homework_2_p5
//
//  Created by Zegao Liu on 16/4/24.
//  Copyright © 2016年 Zegao Liu. All rights reserved.
//

#include <iostream>
#include <string>
#include <stack>
 #include <cassert>
using namespace std;

int evaluate(string infix, string& postfix, bool& result)
// Evaluates a boolean expression
//   If infix is a syntactically valid infix boolean expression,
//   then set postfix to the postfix form of that expression, set
//   result to the value of the expression, and return zero.  If
//   infix is not a syntactically valid expression, return 1; in
//   that case, postfix may or may not be changed, but result must
//   be unchanged.)
{
    
    /*	Initialize postfix to empty
     Initialize the operator stack to empty
     For each character ch in the infix string
	    Switch (ch)
     case operand:
     append ch to end of postfix
     break
     case '(':
     push ch onto the operator stack
     break
     case ')':
     // pop stack until matching '('
     While stack top is not '('
     append the stack top to postfix
     pop the stack
     pop the stack  // remove the '('
     break
     case operator:
     While the stack is not empty and the stack top is not '('
     and precedence of ch <= precedence of stack top
     append the stack top to postfix
     pop the stack
     push ch onto the stack
     break
     While the stack is not empty
	    append the stack top to pos
     */
    

    stack<char> temp;
    
    postfix = "";
    
    //Convert the infix to postfix
        for (int i=0; i < infix.length(); i++)
        {
            switch ( infix[i])
            {
                
                case 'T':
                case 'F':
                    postfix.append(&infix[i],1);
                    break;
                case '(' :
                    temp.push(infix[i]);
                    break;
                case ')':
                    
                    //exam: what is wrong?
                     while ( temp.top() != '(')
                         
                         //exam: Is it valid to do this ,1?
                     {   postfix.append(&temp.top(),1);
                         temp.pop();
                     }
                    temp.pop();
                
                    break;
                case '|':
                case '&':
                case '!':
                    //exam: what is precedence of ch ? Is the statement condition correct?
                    while(!temp.empty() && temp.top() != '('&& temp.top() == '!')
                    {
                        postfix.append(&temp.top(),1);
                        temp.pop();
                    }
                
                    temp.push(infix[i]);
                        
                    break;
                default: break;
                
            }
        }
    
    //What's wrong with it?
   while(!temp.empty())
    {
        postfix.append(&temp.top(),1);
        temp.pop();
    }

    /*
     Initialize the operand stack to empty
     For each character ch in the postfix string
	    if ch is an operand
     push the value that ch represents onto the operand stack
	    else // ch is a binary operator
     set operand2 to the top of the operand stack
     pop the stack
     set operand1 to the top of the operand stack
     pop the stack
     apply the operation that ch represents to operand1 and
     operand2, and push the result onto the stack
     When the loop is finished, the operand stack will contain one item,
     the result of evaluating the expression
     */
    
    stack<char> operand;
    char operand1;
    char operand2;
    char answer;
    for (int i=0; i < postfix.length(); i++)
    {
        if ( postfix[i] == 'T' || postfix[i] == 'F' )
            operand.push(postfix[i]);
        else //postfix[i] is an operator and start calculation
        {
            operand2 = operand.top();
            operand.pop();
            operand1 = operand.top();
            operand.pop();
            
            //operator !
            if( postfix[i] == '!')
            {   if ( operand2 == 'T')
                    operand2 = 'F';
                if ( operand2 == 'F')
                    operand2 = 'T';
                operand.push(operand1);
                operand.push(operand2);
            }
            
            //operator &
            if( postfix[i] == '&' )
            {   if ( operand2 == 'T')
                    {
                        if (operand1 == 'F')
                            answer = 'F';
                        else if(operand1 == 'T')
                            answer = 'T';
                    }
                
                if(operand2 == 'F')
                    {
                        if (operand1 == 'F')
                            answer = 'F';
                        else if(operand1 == 'T')
                            answer = 'F';
                    }
                
                operand.push(answer);
            }
            
            //operator |
            if( postfix[i] == '|' )
            {   if ( operand2 == 'T')
                {
                    if (operand1 == 'F')
                        answer = 'T';
                    else if(operand1 == 'T')
                        answer = 'T';
                }
                
                if(operand2 == 'F')
                {
                    if (operand1 == 'F')
                        answer = 'F';
                    else if(operand1 == 'T')
                        answer = 'T';
                }
                operand.push(answer);
            }
            
        }
        
    }
   
   
    if( operand.top() == 'T')
        result = true;
    if(operand.top() == 'F')
        result = false;
    
    
  
    return 0;
}

//exam: delete
void test(char& a)
{
    switch (a)
    {
    case 'T':
    case 'F':
    cout << "T or F" << endl;
    break;
        default: cout<< "Not T or F" << endl;
            break;
    }
}


int main()
{
/*    string pf;
    bool answer;
    a = evaluate("T | f", string& postfix, bool& result);
    
*/
    string a = "(T&(F|F))";
    string postfix = "";
    stack<char> b;
    b.push('A');
    b.push('B');
    bool answer;
    int n = evaluate(a,postfix,answer);
    //postfix.append(&b.top());
    cout << postfix << endl;
    
    
}


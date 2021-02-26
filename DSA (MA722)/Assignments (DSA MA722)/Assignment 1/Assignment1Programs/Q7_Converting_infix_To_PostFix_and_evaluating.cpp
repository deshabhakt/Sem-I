#include<iostream>
#include<math.h>
using namespace std;
class Node
{
    public:
    char data;
    Node* next;
    Node()
    {
        data=0;
        next=NULL;
    }
    Node(char d)
    {
        data=d;
    }
};
class stack
{
    public:
    int strlen;
    Node* top;
    stack()
    {
        top=NULL;
        strlen=0;
    }
    void push(Node* n)
    {
        if(top==NULL)
        {
            top=n;
        }
        else
        {
            Node* temp=top;
            top=n;
            n->next=temp;

        }
    }
    char pop()
    {
        Node* temp=NULL;
        if(top==NULL)
        {
            cout<<"stack underflow";
        }
        else
        {
            temp=top;
            top=top->next;
        }
        return temp->data;
    }
    int getstrlen(string s)
    {
        while(s[this->strlen]!='\0')
        {
            this->strlen++;
        }
        return this->strlen;
    }
    int prec(char c)
    {
        if (c == '^')
            return 3;
        else if (c == '*' || c == '/')
            return 2;
        else if (c == '+' || c == '-')
            return 1;
        else
            return -1;
    }
    string infixToPostFix(string s)
    {
    int l = getstrlen(s); 
    string ns; 
    for(int i = 0; i < l; i++) 
    {   
        Node* temp=new Node();
        if((s[i] >= 'a' && s[i] <= 'z') ||  (s[i] >= 'A' && s[i] <= 'Z') || isdigit(s[i])) 
        {
            ns+=s[i]; 
        }
        else if(s[i] == '(') 
        {
            temp->data='(';
            push(temp); 
        }  
        else if(s[i] == ')') 
        { 
            while(top!= NULL && top->data != '(') 
            { 
                char c = top->data; 
                pop(); 
               ns += c; 
            } 
            if(top->data == '(') 
            { 
                char c = top->data; 
                pop(); 
            } 
        } 
        else
        { 
            while(top!= NULL && prec(s[i]) <=prec(top->data)) 
            { 
                char c = top->data; 
                pop(); 
                ns += c; 
            } 
            temp->data=s[i];
            push(temp); 
        } 
    }
     while(top!=NULL) 
    { 
        char c = top->data; 
        pop(); 
        ns += c; 
    } 
    return ns;
    }
    void findvalueofpostfix(string s)
    {
        string ns;
        for(int i = 0; s[i]; i++) 
        {   
            Node* temp=new Node();
            if(isdigit(s[i]))
            {
                temp->data=s[i]-'0';
                push(temp); 
            }
            else 
            {
                int a=pop();
                int b=pop();
                switch (s[i])
                {
                case '+':
                    temp->data=a+b;
                    push(temp);
                    break;
                case '-':
                    temp->data=a-b;
                    push(temp);
                    
                    break;
                case '*':
                    temp->data=a*b;
                    push(temp);
                    break;
                case '/':
                    temp->data=a/b;
                    push(temp);
                    break;
                case '^':
                    temp->data =pow(a,b);
                    push(temp);
                    break;
                }
            }
        }
        cout << "Value is " <<  (int) pop() <<endl;
    }
    bool checkIfDigit(string s)
    {
        bool digit=false;
        for(int i=0;s[i];i++)
        {
            if(isdigit(s[i]))
                digit=true;
            else
                continue;
        }
        return digit;
    }
};
int main() 
{ 
    stack st;
    string exp,postfix,eval;
    cout << "\n=====================================================================================" << endl;
    cout << "******************** Infix To Postfix Conversion and evaluation *********************" << endl;
    cout << "=====================================================================================" << endl;
    cout << "Enter Expression:";
    cin >> exp; 
    postfix=st.infixToPostFix(exp);
    cout << "Postfix Expression is " << postfix<<endl;
    if(st.checkIfDigit(postfix))
        st.findvalueofpostfix(postfix);
    return 0; 
} 
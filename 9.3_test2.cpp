/*
THE DIFERENCE BETWEEN THE FUNCTIONS 1, 2 AND 3:
    1: RETURNING A CONST REFERENCE PREVENTS CHANGING THE RETURNED (BY CONST REFERENCE) OBJECT IN THE MAIN FUNCTION
    2: CONST-QUALIFIED MEMBER FUNCTIONS (THAT RETURN A CONST REFERENCE) CANNOT CHANGE THE OBJECT INSIDE THAT FUNCTION 
    3. MEMBER FUNCTION THAT RETURN A COPY AND IS CONST-QUALIFIED CAN CHANGE THE COPY OF THE OBJECT BUT NOT THE OBJECT
*/

#include "D:\Dropbox\XPS15 Files\3. Programming\GitHub\std_lib_facilities.h"

class Name_pairs
{
public:
    const vector<string> &get_name1()
    {
        name.push_back("gn1"); // can change the object inside the member function
        return name;
    }

    const vector<string> &get_name2() const
    {
        //name.push_back("gn2"); // cannot change the object name inside this const-qualified member function
        return name;
    }

    vector<string> get_name3() const
    {
        return name;
    }

private:
    vector<string> name = {"ab"};
};

int main()
{
    Name_pairs np1; // np1 object should be the same like "name"
    //np1.get_name1().push_back("gn1");   // cannot change an object returned by const reference
    cout << "\nnp1 object from main: ";
    for (string s : np1.get_name1())
        cout << s << " ";

    Name_pairs np2;
    //np2.get_name2().push_back("gn2");   // cannot change an object returned by const reference
    cout << "\nnp2 object from main: ";
    for (string s : np2.get_name2())
        cout << s << " ";

    Name_pairs np3;
    np3.get_name3().push_back("gn3"); // this should change np3 to have {ab, gn3} but it only holds "ab"
    cout << "\nnp3 object from main: ";
    for (string s : np3.get_name3()) 
        cout << s << " ";
}

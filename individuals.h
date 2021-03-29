#include <iostream>
#include <string>
using namespace std;

template<class T>

class Individuals
{
    public:
        Individuals(string name, T type, int counter, string job){
            this->name = name;
            this->type = type;
            this->counter = counter;
            this->job = job;
        };
        T type;

        string getName()
        {
            return this->name;
        }

        T &getType()
        {
            return this->type;
        }

        string getJob()
        {
            return this->job;
        }

        int getCounter()
        {
            return this->counter;
        }


        bool  operator<(const Individuals<T> & i) const
        {
            if (i.name != name)
            {
                    return name < i.name;
            }
            else
            {
                return counter < i.counter;
            }
        }
        
        void printA()
        {

            if (this->name == this->job)
            {
                cout << this->name << "\t" << this->counter << endl;
                cout << this->type << endl;
            }

            else
            {
                cout << this->name << endl;
                cout << "\t" << this->job << endl;
                cout << "\t" << this->type << endl;
            }
        }


    protected:
        string name;
        int counter;
        string job;
};

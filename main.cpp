#include "iostream"
#include "fstream"


using namespace std;

class listNode
{
public:
    string data;
    listNode* next;

    listNode() {
        data = "";
        next = NULL;
    }

    listNode(string d) {
        data = d;
        next = NULL;
    }
    string printNode() {
        string s;
        if (next==NULL) {
            s = "(" +data + ", end)->";
        }else
        s = "(" + data + ", " + next->data + ")->";
        return s;
    }
};

class LLStack {
private:
    listNode* top;

public:
    LLStack() {
        top = new listNode("dummy");
    }

    void push(string name) {
        listNode* curr = top;
        while (curr->next) {
            curr = curr->next;
        }listNode* ln = new listNode(name);
        curr->next = ln;
        
    }

    bool isEmpty() {
        if (top->next == NULL) {
            return true;
        }
        else return false;
    }

    listNode* pop() {
        if (!isEmpty()) {
            listNode* curr = top;
            while (curr->next->next != NULL) {
                curr = curr->next;
            }
            delete (curr->next);
            curr->next = NULL;
            return top;
        }
    }

    void buildStack(LLStack S, string inFile, string outFile1) {
        ifstream input;
        input.open(inFile);
        ofstream outputFile;
        outputFile.open(outFile1);
        string name;
        char sign;
        while (input.eof() == false) {
            input >> sign >> name;
            outputFile << sign << name << endl;
            if (sign == '+') {
                S.push(name);
            }
            else if (sign == '-') {
                if (!S.isEmpty()) {
                    S.pop();
                }
                else outputFile << endl << "stack is empty." << endl;
            }
        }input.close();
        outputFile.close();
        printStack(outFile1);
    }

    void printStack(string outFile1) {
        ofstream outputFile;
        outputFile.open(outFile1, ios::app);
        listNode* current = top;
        outputFile << endl << "TOP->"<<current->printNode();
        while (current->next != NULL) {
            current = current->next;
            outputFile << current->printNode();
        }outputFile << "Null" << endl;
        outputFile.close();
    }

};

class LLQueue {
private:
    listNode* head;
    listNode* tail;

public:
    LLQueue() {
        head = new listNode("dummy");
        tail = head;
    }

    void insertQ(string name) {
        listNode* ln = new listNode(name);
        tail->next = ln;
        tail = tail->next;
    }

    bool isEmpty() {
        if (head->next == tail) {
            return true;
        }
        else return false;
    }

    listNode* deleteQ() {
        if (!isEmpty()) {
            listNode* temp = head->next;
            head->next = head->next->next;
            return temp;
        }
    }

    void buildQueue(LLQueue Q, string inFile, string outFile2) {
        ifstream input;
        input.open(inFile);
        ofstream outputFile;
        outputFile.open(outFile2);
        string name;
        char sign;
        while (input.eof() == false) {
            input >> sign >> name;
            outputFile << sign << name << endl;
            if (sign == '+') {
                Q.insertQ(name);
            }
            else if (sign == '-') {
                if (!Q.isEmpty()) {
                    Q.deleteQ();
                }
                else outputFile << endl << "Queue is empty" << endl;
            }
        }input.close();
        outputFile.close();
        printQueue(outFile2);
    }

    void printQueue(string outFile2) {
        ofstream outputFile;
        outputFile.open(outFile2, ios::app);
        listNode* current = head;
        outputFile << endl << "TOP->" << current->printNode();
        while (current->next != NULL) {
            current = current->next;
            outputFile << current->printNode();
        }outputFile << "Null" << endl;
    }

};

int main(int argc, const char* argv[])
{
    ifstream inFile;
    inFile.open(argv[1]);
    if (!inFile.is_open()) {
        cout << "Unable to open file" << endl;
        exit(1);
    }
    LLStack S;
    S.buildStack(S, argv[1], argv[2]);
    inFile.close();

    inFile.open(argv[1]);
    if (!inFile.is_open()) {
        cout << "Unable to open file" << endl;
        exit(1);
    }
    LLQueue Q;
    Q.buildQueue(Q, argv[1], argv[3]);
    inFile.close();
    

}

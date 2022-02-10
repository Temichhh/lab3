
#include <iostream>
#include <stdexcept>
#include "WorkflowExecutor.h"


using namespace std;
using namespace Workflow;


int main(int argc, char* argv[]) {

    try {
        if(argc!=2)
            throw runtime_error("Wrong count of args in main");

        WorkflowExecutor executor;
        executor.loadFromFile(argv[1]);
        executor.execute();
    }
    catch(exception& ex){
        cout << ex.what() << endl;
    }

    return 0;
}

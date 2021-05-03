#include <map>
using namespace std;

namespace pandemic {

    class Board {
        private:
            map <string, int> _disease_map;
        public:
            Board();
            int& operator[] (string key);
    };
}
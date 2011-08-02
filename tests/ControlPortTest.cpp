#include <cxxtest/TestSuite.h>

#include "../gen/FluteMeta.h"
#include "../gen/Flute.peg"        
      
class ControlPorttest : public CxxTest::TestSuite {
    public:
        void testInRange() {
            for (int i = 0; i < p_n_ports -3; i++) {
                TS_ASSERT_LESS_THAN_EQUALS(p_port_meta[i].min, p_port_meta[i].default_value);
                TS_ASSERT_LESS_THAN_EQUALS(p_port_meta[i].default_value, p_port_meta[i].max);
            }
       }

};

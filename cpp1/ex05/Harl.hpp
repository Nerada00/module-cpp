#include <iostream>
#include <cctype>

class Harl {
typedef void (Harl::*t_func) (void);

private:
    void debug( void );
    void info( void );
    void warning( void );
    void error( void );
    t_func _ptr[4];

public:
    Harl(void);
    void complain( std::string level );
};

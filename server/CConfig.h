#ifndef CCONFIG_H
#define CCONFIG_H


class CConfig
{
public:
    static int min_coord() {
        return 0;
    }

    static int max_coord() {
        return 1000;
    }

    static int min_velocity() {
        return -1000;
    }

    static int max_velocity() {
        return 1000;
    }

    //количество возможных направлений
    static int direction_count() {
        return 360;
    }
};

#endif // CCONFIG_H

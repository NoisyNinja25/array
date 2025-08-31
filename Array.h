#ifndef ARRAY_H
#define ARRAY_H

class Array {
    public:
        Array();
        Array(unsigned int length);
        Array(unsigned int length, char fill);

        unsigned int get_size();
        unsigned int get_max_size();

        char get_element(unsigned int index);
        void set_element(unsigned int index, char el);

        void resize(unsigned int length);
        void shrink();
        int find(char target);

    private:
        char * m_data;
        unsigned int m_cur_size;
        unsigned int m_max_size;

        void reallocate_(unsigned int length);

};

#endif 
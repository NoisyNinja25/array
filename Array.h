#ifndef ARRAY_H
#define ARRAY_H

class Array {
    public:
        Array();
        Array(unsigned int length);
        Array(unsigned int length, char fill);
        Array(const Array & arr);
        ~Array();

        unsigned int get_size() const;
        unsigned int get_max_size() const;

        char get_element(unsigned int index) const;
        void set_element(unsigned int index, char el);

        void resize(unsigned int length);
        void shrink();
        int find(char target);

        void fill(char el);

        void reverse();

        Array slice(unsigned int begin) const;
        Array slice(unsigned int begin, unsigned int end) const;

        char & operator [] (unsigned int index);
        const char & operator [] (unsigned int index) const;
        
        bool operator == (Array & rhs) const;
        bool operator != (Array & rhs) const;

    private:
        char * m_data;
        unsigned int m_cur_size;
        unsigned int m_max_size;

        void reallocate_(unsigned int length);

};

#endif 
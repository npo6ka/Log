#pragma once
#define LOG_ENABLED 1

#define FILE_NAME "progLog"
#define OLD_LOG "previousLog"
#define EXTENSION "log"

#define BOOL_TO_WORD 0;       // 0 - false, other - true
#define SIX_DECIMAL_PLACES 1; // for double and float format

#if LOG_ENABLED
    #include <fstream>
    #include <stdio.h>
    #include <sstream>

    using namespace std;

    class Logging {
        template<typename ... Arguments>
        friend void outlog(Arguments&& ... args);

        ofstream fout;

        Logging();
        ~Logging();
        Logging(const Logging&) = delete;
        Logging& operator=(const Logging&) = delete;

        template<typename ... Arguments>
        void outLog(Arguments&& ... args) {
            stringstream *stream = new stringstream();
            shapeString(stream, args...);
            fout << stream->str() + "\n";
            delete stream;
        }

        template<typename T, typename ... Arguments>
        void shapeString(stringstream *st, T format, Arguments&& ... args) {
            putStream(st, format);
            shapeString(st, args...);
        }

        template<typename T>
        void shapeString(stringstream *st, T format) {
            putStream(st, format);
        }

        template <typename UNK_TYPE>
        inline void putStream(stringstream *st, UNK_TYPE arg) {
            *st << arg;
        }

        inline void putStream(stringstream *st, const bool arg) {
        #if BOOL_TO_WORD
            *st << arg ? "true" : "false";
        #else
            *st << arg ? "1" : "0";
        #endif
        }

        #if SIX_DECIMAL_PLACES
        inline void putStream(stringstream *st, const float arg);
        inline void putStream(stringstream *st, const double arg);
        #endif
    public:
        static Logging& getInstance() {
            static Logging instance;
            return instance;
        }
    };

    template<typename ... Arguments>
    void outlog(Arguments&& ... args) {
        Logging::getInstance().outLog(args...);
    }
#else
    template<typename ... Arguments>
    void outlog(Arguments&& ... args) {}
#endif




#include "log.h"

Logging::Logging() {
    string fileNew = (string(FILE_NAME) + "." + EXTENSION);
    string fileOld = (string(OLD_LOG) + "." + EXTENSION);

    int i = remove(fileOld.c_str());
    int j = rename(fileNew.c_str(), fileOld.c_str());

    fout = ofstream(fileNew);
}

Logging::~Logging() {
    fout.close();
}

inline void putStream(stringstream *st, const bool arg) {
#if BOOL_TO_WORD
    *st << arg ? "true" : "false";
#else
    *st << arg ? "1" : "0";
#endif
}

#if SIX_DECIMAL_PLACES
inline void putStream(stringstream *st, const float arg) {
    *st << to_string(arg);
}
inline void putStream(stringstream *st, const double arg) {
    *st << to_string(arg);
}
#endif

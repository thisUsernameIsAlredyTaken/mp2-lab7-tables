#include "tarrayhash.h"

int TArrayHash::GetNextPos(int pos) {
    return (pos + HashStep) % TabSize;
}

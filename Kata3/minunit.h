/* file: minunit.h */
#define muAssert(message, test) do { if (!(test)) return message; } while (0)
#define muRunTest(test) do { char *message = test(); testsRun++; \
if (message) return message; } while (0)
extern int testsRun;
//g

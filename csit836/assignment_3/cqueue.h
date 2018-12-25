
const int MAX = 4;

struct Passenger {
    char name[80];
};

class CQueue {
private:
int front;
int rear;
Passenger passengers[MAX];
 
public:
CQueue();
bool IsEmpty(void); 
bool IsFull(void); 
void Enqueue();
Passenger Front(void);
void Dequeue(void); 
};

#include <stdio.h>
#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int data)
{
if(rear == MAX - 1)
printf("Queue is Full\n");
else
{
if(front == -1)
front = 0;

queue[++rear] = data;
}
}

int dequeue()
{
int data;

if(front == -1 || front > rear)
{
printf("Queue is Empty\n");
return -1;
}

data = queue[front++];

if(front > rear)
front = rear = -1;

return data;
}

int main()
{
int n, i, data;

printf("Enter number of bytes to transmit: ");
scanf("%d", &n);

printf("\nTransmitting Data:\n");

for(i = 0; i < n; i++)
{
printf("Enter byte: ");
scanf("%d", &data);
enqueue(data);
}

printf("\nReceiving Data:\n");

while(front != -1)
{
data = dequeue();
printf("Received Byte: %d\n", data);
}

return 0;
}

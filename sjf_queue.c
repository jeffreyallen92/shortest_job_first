#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "SJF.h"

//------------------------------------------------------------------------------
// This function will add data to the queue. Its parameters includes the record
// which is being added to the queue and the queue itself. Because it should 
// not return anything, it is a void function.
void insert(struct Job record, struct LinkedList *queue)
{ 
    //struct Node* previous = (struct Node*) malloc(sizeof(struct Node));
    //previous =  NULL; //(struct Node*)malloc(sizeof(struct Node));
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    
    for(int i = 0; i < 4; i++)
    {
       newNode->job.name[i] = record.name[i]; 
    }

    newNode->job.arrivalTime = record.arrivalTime;
    newNode->job.serviceTime = record.serviceTime;
    newNode->job.priority = record.priority;
    newNode->next = NULL;
    
    // If linked list is empty...
    if(queue->front == NULL)
    {       
        newNode->next = NULL;
        queue->front = newNode;
    }
    
    // If new current service time is less than current front's service time,
    // front = new node 
    printf("%d \n", (record.serviceTime));
    printf("%d \n", (queue->front->job.serviceTime));
    if(record.serviceTime < queue->front->job.serviceTime)
    {
        newNode->next = queue->front;
        queue->front = newNode;
    }

    else
    {
        struct Node* temp  = (struct Node*) malloc(sizeof(struct Node));
        struct Node* prev  = (struct Node*) malloc(sizeof(struct Node));
        temp = queue->front;
        while(temp != NULL && (record.serviceTime >= temp->job.serviceTime))
        {
            prev = temp;
            temp = temp->next;
        }
        //newNode->next = temp;
        prev->next = newNode;
        newNode->next-> next = temp; 
    }
        /*while(queue->front != NULL (record.serviceTime >= temp->serviceTime)) 
        {           
            if(record.serviceTime > queue->front->serviceTime)          
            {
                //Traverse to location where the node needs to be inserted
                previous = queue->front;    
                queue->front = queue->front->next;
            }   
            
            else
            {
                //Insert the node
                printf("Insert node... \n");
                previous = newNode->next;
                //previous->next = newNode; 
                //previous = newNode; 
                newNode->next = queue->front; 
                //previous = queue->front;
                previous = newNode->next;
                queue->front = queue->front->next;
            }               
        }
        printf("Insert node finished \n");
        //newNode->next = queue->front;
        previous->next = newNode; 
        printf("Insert node finished \n");
    }
*/
  /*  
    struct Node* previous = (struct Node*) malloc(sizeof(struct Node));
    //previous = NULL;
    previous = NULL;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        
    for(int i = 0; i < 4; i++)
    {
       newNode->name[i] = record.name[i]; 
    }

    newNode->arrivalTime = record.arrivalTime;
    newNode->serviceTime = record.serviceTime;
    newNode->priority = record.priority;
    newNode->next = NULL;
    
    // If linked list is empty...
    if(queue->front == NULL && queue->back == NULL)
    {   
       // newNode->next = NULL;
        queue->front = newNode;
    }

    
    // If new node's service time is less than current front's service time,
    // front = new node 
   // printf("%d \n", (newNode->serviceTime));
   // printf("%d \n", (queue->front->serviceTime));
    /*if((newNode->serviceTime) < (queue->front->serviceTime))
    {
        printf("Hello4 \n");
        newNode->next = queue->front;
        queue->front = newNode;
    }

    else 
    {
      
        while((newNode->serviceTime) >= (queue->front->serviceTime) && queue->front != NULL)    
        {   
          // printf("Hello6 \n");
          // if((newNode->serviceTime) > (queue->front->serviceTime))           
           //{
                //Traverse to location where the node needs to be inserted
                printf ("Finding node position \n");
                previous = queue->front;    
                queue->front = queue->front->next;
        }   

            //else
            //{
               //Insert the node
               printf("Insert node... \n");
               previous->next = (struct Node*) malloc(sizeof(struct Node));
               //printf("Insert node2 \n");
               previous->next = newNode;
               printf("Insert node3 \n");
               newNode->next = queue->front;    
               printf("Insert node finished \n");
            //}             
        //}
        printf("Hello8 \n");
        previous->next = newNode; 
    //}        
    }
    printf("added \n");
     */
}

//------------------------------------------------------------------------------
// This function will delete an element from the queue. Its parameters include
// the queue in which a job will be deleted. 
struct Job* dequeue(struct LinkedList *queue)
{    
    struct Node* temp = queue->front;
    struct Node* recordInfo = temp;
        
    if((queue->front == NULL))//&& (queue->back == NULL)) 
    {
       printf("Dequeue: Queue empty \n");  
    }
        
    // If there is only one element in queue
    else if(queue->front == queue->back) 
    {
        queue->front = NULL;
        queue->back = NULL;
    }
        
    else 
    {
        queue->front = queue->back->next;
    }
        
    temp = temp->next;
    free(queue->front); 
    queue->front = temp;
    
    return recordInfo; 
}

//------------------------------------------------------------------------------
// This function will read input from a file. Its parameter includes the record
// array which the input will be stored into. 
void readFile(struct Job record[])
{    
    FILE *filePtr;
    filePtr = fopen("input.txt", "r"); 
    
    
    if(filePtr == NULL)
    {
        printf("Could not open file. \n");
    }
    
    
    else
    {
        // Storing items from file into an array of jobs.       
        for(int i = 0; i < 4; i++)
        {
            fscanf(filePtr, "%s %d %d %d", &record[i].name, 
                    &record[i].arrivalTime, &record[i].serviceTime, 
                    &record[i].priority);                        
        }
    }

    fclose(filePtr);
}

//------------------------------------------------------------------------------
// This function will output the jobs as they are completed to a file named 
// output.txt. 
//void outputFile()
//{
//    
//}


//------------------------------------------------------------------------------
// This function will tell whether the queue is empty or not. Its parameters
// include the queue. It will return a false if it is not empty or true if it
// is empty. 
bool isEmpty(struct LinkedList *queue)
{
    if ((queue->front == NULL) && (queue->back == NULL))
    {
        return true;
    }
    
    else
    {
        return false;
    }
}
//------------------------------------------------------------------------------
// This function will print the queue. Its parameters include the queue which
// needs to be printed.
void print_queue(struct LinkedList* queue)
{
    struct Node *ptr = queue->front;
    
    printf("\n");
    
    if(ptr == NULL){
        printf("Queue is empty \n");
    }
    
    while(ptr != NULL)
    {
        printf("%s %d %d %d", ptr->job.name, ptr->job.arrivalTime, 
                  ptr->job.serviceTime, ptr->job.priority); 
        printf("\n");
        ptr = ptr->next;
    }
    
    return;
}






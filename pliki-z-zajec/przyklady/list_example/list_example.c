
/*
   C Linked List Data Structure
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
} node;

typedef void (*callback)(node* data);

/*
    create a new node
    initialize the data and next field

    return the newly created node
*/
node* create(int data,node* next)
{
    node* new_node = (node*)malloc(sizeof(node));
    if(new_node == NULL)
    {
        printf("Error creating a new node.\n");
        exit(0);
    }
    new_node->data = data;
    new_node->next = next;

    return new_node;
}

/*
    add a new node at the beginning of the list
*/
node* prepend(node* head,int data)
{
    node* new_node = create(data,head);
    head = new_node;
    return head;
}

/*
    add a new node at the end of the list
*/
node* append_node(node* head, int data)
{
    node *curr = head;

    if (head == NULL)
        return NULL;
    /* go to the last node */
    while (curr->next != NULL)
        curr = curr->next;

    /* create a new node */
    node* new_node = create(data,NULL);
    curr->next = new_node;

    return head;
}

/*
    insert a new node after the prev node
*/
node* insert_after(node *head, int data, node* prev)
{
    node *curr = head;

    if (head == NULL || prev == NULL)
        return NULL;
    /* find the prev node, starting from the first node*/
    while (curr != prev)
        curr = curr->next;

    if (curr != NULL)
    {
        node* new_node = create(data,curr->next);
        curr->next = new_node;
        return head;
    }
    else
    {
        return NULL;
    }
}

/*
    insert a new node before the nxt node
*/
node* insert_before(node *head, int data, node* nxt)
{
    node *curr = head;

    if (nxt == NULL || head == NULL)
        return NULL;

    if (head == nxt)
    {
        head = prepend(head,data);
        return head;
    }

    /* find the prev node, starting from the first node*/

    while (curr != NULL)
    {
        if(curr->next == nxt)
            break;
        curr = curr->next;
    }

    if (curr != NULL)
    {
        node* new_node = create(data,curr->next);
        curr->next = new_node;
        return head;
    }
    else
    {
        return NULL;
    }
}

/*
    traverse the linked list
    if callback type was not defined function could be
    declared like this
    void traverse_list(node* head, void (*f)(node *));
*/
void traverse_list(node* head, callback f)
{
    node* curr = head;

    while(curr != NULL)
    {
        f(curr);
        curr = curr->next;
    }
}
/*
    remove node from the front of list
*/
node* remove_at_front(node* head)
{
    if (head == NULL)
        return NULL;
    node *front = head;
    head = head->next;
    front->next = NULL;
    /* is this the last node in the list */
    if (front == head)
        head = NULL;
    free(front);
    return head;
}

/*
    remove node from the back of the list
*/
node* remove_at_back(node* head)
{
    node *curr = head;
    node *back = NULL;

    if (head == NULL)
        return NULL;
    while(curr->next != NULL)
    {
        back = curr;
        curr = curr->next;
    }

    if (back != NULL)
        back->next = NULL;

    /* if this is the last node in the list*/
    if (curr == head)
        head = NULL;

    free(curr);

    return head;
}

/*
    remove a node from the list
*/
node* remove_arb_node(node* head,node* nd)
{
    if (nd == NULL)
        return NULL;
    /* if the node is the first node */
    if (nd == head)
        return remove_at_front(head);

    /* if the node is the last node */
    if (nd->next == NULL)
        return remove_at_back(head);

    /* if the node is in the middle */
    node* curr = head;
    while(curr != NULL)
    {
        if (curr->next == nd)
            break;
        curr = curr->next;
    }

    if (curr != NULL)
    {
        node* tmp = curr->next;
        curr->next = tmp->next;
        tmp->next = NULL;
        free(tmp);
    }
    return head;

}
/*
    display a node
*/
void display_content(node* n)
{
    if (n != NULL)
        printf("%d ", n->data);
}

/*
    Search for a specific node with input data

    return the first matched node that stores the input data,
    otherwise return NULL
*/
node* search_data(node* head,int data)
{

    node *curr = head;
    while(curr!=NULL)
    {
        if (curr->data == data)
            return curr;
        curr = curr->next;
    }
    return NULL;
}

/*
    remove all element of the list
*/
void delete_lst(node *head)
{
    node *curr, *tmp;

    if (head != NULL)
    {
        curr = head->next;
        head->next = NULL;
        while(curr != NULL)
        {
            tmp = curr->next;
            free(curr);
            curr = tmp;
        }
    }
}
/*
    return the number of elements in the list
*/
int count_nodes(node *head)
{
    node *curr = head;
    int c = 0;
    while(curr != NULL)
    {
        c++;
        curr = curr->next;
    }
    return c;
}

/*
    reverse the linked list
*/
node* reverse_lst(node* head)
{
    node* prev    = NULL;
    node* current = head;
    node* next;

    while (current != NULL)
    {
        next  = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}
/*
    show the menu
*/
void menu()
{
    printf("--- linked list example menu --- \n\n");
    printf(" 0. menu\n");
    printf(" 1. prepend an element\n");
    printf(" 2. append an element\n");
    printf(" 3. search for an element\n");
    printf(" 4. insert after an element\n");
    printf(" 5. insert before an element\n");
    printf(" 6. remove front node\n");
    printf(" 7. remove back node\n");
    printf(" 8. remove any node\n");
    printf(" 9. Reverse the linked list\n");
    printf("-1. quit\n");

}

int main()
{
    int command = 0;
    int data;

    node* head = NULL;
    node* tmp = NULL;
    callback disp = display_content;

    menu();
    while(1)
    {
        printf("\nSelect a command (0-10, -1 to quit): ");
        scanf("%d",&command);

        if (command == -1)
            break;
        switch(command)
        {
        case 0:
            menu();
            break;
        case 1:
            printf("Please enter a number to prepend: ");
            scanf("%d",&data);

            head = prepend(head,data);
            traverse_list(head,disp);
            break;
        case 2:
            printf("Please enter a number to append_node: ");
            scanf("%d",&data);
            if (head == NULL)
               head = create(data,NULL);
            else
               head = append_node(head,data);
            traverse_list(head,disp);
            break;
        case 3:
            printf("Please enter a number to search: ");
            scanf("%d",&data);
            if (head == NULL)
            {
               printf("head node pointer = NULL\n");
               break;
            }
            else
               tmp = search_data(head,data);
            if(tmp != NULL)
            {
                printf("Element with value %d found.\n",data);
            }
            else
            {
                printf("Element with value %d not found.\n",data);
            }
            break;
        case 4:
            if (head == NULL)
            {
               printf("head node pointer = NULL\n");
               break;
            }
            printf("Enter the element value where you want to insert after: ");
            scanf("%d",&data);
            tmp = search_data(head,data);
            if (tmp != NULL)
            {
                printf("Enter the element value to insert after: ");
                scanf("%d",&data);
                head = insert_after(head,data,tmp);
                if(head != NULL)
                    traverse_list(head,disp);
            }
            else
            {
                printf("Element with value %d not found.\n",data);
            }
            break;
        case 5:
            if (head == NULL)
            {
               printf("head node pointer = NULL\n");
               break;
            }
            printf("Enter the element value where you want to insert before: ");
            scanf("%d",&data);
            tmp = search_data(head,data);
            if (tmp != NULL)
            {
                printf("Enter the element value to insert before: ");
                scanf("%d",&data);
                head = insert_before(head,data,tmp);

                if(head != NULL)
                    traverse_list(head,disp);
            }
            else
            {
                printf("Element with value %d not found.\n",data);
            }
            break;
        case 6:
            if (head == NULL)
            {
               printf("head node pointer = NULL\n");
               break;
            }
            head = remove_at_front(head);
            if (head != NULL)
                traverse_list(head,disp);
            break;
        case 7:
            if (head == NULL)
            {
               printf("head node pointer = NULL\n");
               break;
            }
            head = remove_at_back(head);
            if (head != NULL)
                traverse_list(head,disp);
            break;
        case 8:
            if (head == NULL)
            {
               printf("head node pointer = NULL\n");
               break;
            }
            printf("Enter the element value to remove: ");
            scanf("%d",&data);
            tmp = search_data(head,data);
            if (tmp != NULL)
            {
                remove_arb_node(head,tmp);
                if(head != NULL)
                    traverse_list(head,disp);
            }
            else
            {
                printf("Element with value %d not found. ",data);
            }
            break;
        case 9:
            if (head == NULL)
            {
               printf("head node pointer = NULL\n");
               break;
            }
            head = reverse_lst(head);
            if (head != NULL)
                traverse_list(head,disp);
            break;
        default :
            break; /* break is not necessary here. it should do nothing to handle improper entries in command reading mode */
        }
    }
    delete_lst(head);
    return 0;
}


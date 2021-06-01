#include <iostream>
#include <fstream>

using namespace std;

 enum { kSmaller, kLarger, kSame};

 class Data
 {
 public:
   Data(int val): dataValue(val)
   {
   }
   virtual ~Data()
   {
   }
   virtual int Compare(const Data &);
   virtual void Show()
   {
      cout << dataValue << endl;
   }
 private:
   int dataValue;
 };

 int Data::Compare(const Data & theOtherData)
 {
   if (dataValue < theOtherData.dataValue)
      return kSmaller;
   if (dataValue > theOtherData.dataValue)
      return kLarger;
   else
      return kSame;
 }

 class Node     // abstract data type
 {
 public:
   Node()
   {
   }
   virtual ~Node()
   {
   }
   virtual Node *Insert(Data * theData) = 0;
   virtual void Show() = 0;
 private:
 };

 class InternalNode : public Node
 {
 public:
   InternalNode(Data * theData, Node * next);
   ~InternalNode()
   {
      delete nextNode;
      delete myData;
   }
   virtual Node *Insert(Data * theData);
   virtual void Show()
   {
      myData->Show();
      nextNode->Show();
   }

 private:
     Data * myData;
   Node *nextNode;
 };

 InternalNode::InternalNode(Data *theData, Node *next):
 myData(theData),
 nextNode(next) { }

 Node *InternalNode::Insert(Data * theData)
 {
   int result = myData->Compare(*theData);

   switch (result)
   {
      case kSame:    // fails out i.e. it will be processed like kLarger case
      case kLarger:  // new data to be place before "me" since "my-the caller object"
       {             // myData content was larger (or the same)
                     // "I" i.e. object whose myData was used to call Compare

         InternalNode *dataNode = new InternalNode(theData, this);
         return dataNode;
       }
      case kSmaller:
         nextNode = nextNode->Insert(theData);
         return this;
   }
   return this;
 }

 class TailNode : public Node
 {
 public:
   TailNode()
   {
   }
   ~TailNode()
   {
   }
   virtual Node *Insert(Data * theData);
   virtual void Show()
   {
   }

 private:
 };

 Node *TailNode::Insert(Data * theData)
 {
   InternalNode *dataNode = new InternalNode(theData, this);
   return dataNode;
 }

 class LinkedList : public Node
 {
 public:
   LinkedList();
   ~LinkedList()
   {
      delete nextNode;
   }
   virtual Node *Insert(Data * theData);
   virtual void Show()
   {
      nextNode->Show();
   }
 private:
     Node * nextNode;
 };

 LinkedList::LinkedList()
 {
   nextNode = new TailNode;
 }

 Node *LinkedList::Insert(Data * theData)
 {
   nextNode = nextNode->Insert(theData);
   return this;
 }

 int main()
 {
   Data *pData;
   int val;
   LinkedList ll;

   for (;;)
   {
      cout << "Jaka wartosc chcesz dodac do listy?"
              " (wpisz 0, aby zakonczyc): ";
      cin >> val;
      if (!val)
         break;
      pData = new Data(val);
      ll.Insert(pData);
   }

   cout << "\n\n";
   ll.Show();
   cout << "\n\n";
   return 0;
 }

using System.Collections.Generic;

namespace aisd_csharp
{
    class Program
    {
        static void Main(string[] args)
        {
            Dictionary<string, int> dictionary = new Dictionary<string, int>();
            dictionary.Add("Adam", 1999);
            dictionary.Add("Robert", 1985);
            dictionary.Add("Daniel", 1977);

            List<int> items = new List<int>();
            items.Add(2);
            items.Add(4);
            items.Add(8);

            // FIFO
            Queue<int> queue = new Queue<int>();
            queue.Enqueue(5);
            queue.Enqueue(10);
            queue.Enqueue(15);

            // LIFO
            Stack<int> stack = new Stack<int>();
            stack.Push(10);
            stack.Push(20);
            stack.Push(30);
        }
    }
}

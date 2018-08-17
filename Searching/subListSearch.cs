using System;
using System.Linq;
using System.Collections;

namespace Sublist_Search
{
    public class Node
    {
        private int data;
        private Node next;

        public Node(int val)
        {
            this.Data = val;
            this.Next = null;
        }

        public int Data
        {
            get { return data; }
            set { data = value;}
        }

        public Node next
        {
            get { return next; }
            set { next = value;}
        }
    }

    public class LinkedList
    {
        private Node front, rear;

        public LinkedList()
        {
            this.front = null;
            this.rear = null;
        }

        public void insertNode(int val)
        {
            if(this.front == null) {
                front = new Node(val);
                rear = front;

                return;
            }
            insertEnd(val);
        }

        public void insertEnd(int val)
        {
            rear-> = new Node(val);
            rear = 
        }
    }

    public class GFG
    {
        public static void Main(String[] args)
        {
            
        }
    }

    [] = Console.ReadLine().Split(' ').Select(.Parse).ToArray();
    
}
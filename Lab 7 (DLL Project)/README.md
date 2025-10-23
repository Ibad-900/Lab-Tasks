🧮 Doubly Linked List – Practical Tasks

Course: Data Structures & Algorithms
Instructor: Syed Shayan Ali Shah
Topic: Doubly Linked List (C++ Implementation)
Student: [Your Name]


---

📘 Overview

This project demonstrates a Doubly Linked List (DLL) using C++.
Each node contains three parts:

data → an integer value

next → pointer to the next node

prev → pointer to the previous node


The DLL class handles:

insertion (at beginning, end, and specific position)

deletion (from beginning)

display (entire list or a single node)

destructor (to free memory at the end)



---

🧩 Tasks Completed

🧱 Task 1 – Destructor

Goal: Free all allocated nodes at program termination.
Output Example:

Deleting Node: 10
Deleting Node: 20
Deleting Node: 30
All nodes deleted successfully!


---

📍 Task 2 – Fix insertAtPos()

Goal: Ensure insertion works at any position, including the last.
Fixed: Logic now properly connects previous and next pointers even when inserting at the end.


---

🗑️ Task 3 – Fix deleteFB()

Goal: Correctly delete the first node and update the head pointer.
Fixed: New head now points to the next valid node and avoids dangling pointers.


---

🔍 Task 4 – Fix DisplayNode()

Goal: Display only one specific node with proper addresses.
Output Example:

------------------------------------------------------
 Prev Address        |  Data  |  Next Address  |  Node Address
------------------------------------------------------
 0x0000000000000000  |   25   | 0x0000000000AA | 0x0000000000CC
------------------------------------------------------


---

🧠 Visual Representation

Before Insertion

NULL <- [10] <-> [20] <-> [30] -> NULL

After Inserting 40 at End

NULL <- [10] <-> [20] <-> [30] <-> [40] -> NULL

After Deleting First Node

NULL <- [20] <-> [30] <-> [40] -> NULL


---

💻 Sample main() Execution

int main() {
    DLL list;

    list.insertAtBegin(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);
    list.insertAtPos(5, 50);

    list.Display();

    list.deleteFB();
    list.Display();

    list.search(30);
    return 0;
}


---

⚙️ Compilation & Execution

Windows

g++ dll_tasks.cpp -o dll
dll

Linux/Mac

g++ dll_tasks.cpp -o dll
./dll


---

📁 Folder Structure

DLL_Project/
│
├── dll_tasks.cpp
├── README.md
└── output_screenshot.png


---

🏁 Learning Outcomes

By completing this project, I have: ✅ Strengthened understanding of pointer manipulation
✅ Practiced memory management and destructors
✅ Debugged segmentation faults
✅ Gained hands-on experience with linked list operations


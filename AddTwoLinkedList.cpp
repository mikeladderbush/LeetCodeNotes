class Solution
{
public:
    // we are given two ListNode pointers and we need to return one.
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {

        // First we create a dummy listNode that uses the integer only constructor. This will represent the first node created.
        // Then we create another node to represent the end of the list, like the expanding tail of a snake game.
        ListNode *dummyHead = new ListNode(0);
        ListNode *tail = dummyHead;

        // We define a carryover integer for our calculations.
        int carry = 0;

        // We then define a loop that will continue as long as there are more numbers in the lists or if there is a carried value.
        while (l1 != nullptr || l2 != nullptr || carry != 0)
        {

            // The digit in the linked list as long as there is a node available is the value variable from the struct.
            int digit1 = (l1 != nullptr) ? l1->val : 0;
            int digit2 = (l2 != nullptr) ? l2->val : 0;

            // With both values we can add them up with the carry to give up the sum for that digits place.
            int sum = digit1 + digit2 + carry;

            // The digit is then modulo with 10 to give the digit and the carry is calculated by dividing by ten.
            int digit = sum % 10;
            carry = sum / 10;

            // With the expected answer calculated for that place we create a new node using that value.
            // Then we make the next node that the tail points to the newNode. Then we make the tail that newly added node.
            // This means that the tail node creates a node and then becomes that node, leaving the head node behind.
            ListNode *newNode = new ListNode(digit);
            tail->next = newNode;
            tail = tail->next;

            // If l1 is not a nullptr it is equal to the next ptr.
            l1 = (l1 != nullptr) ? l1->next : nullptr;
            l2 = (l2 != nullptr) ? l2->next : nullptr;
        }

        ListNode *result = dummyHead->next;
        delete dummyHead;
        return result;
    }
};
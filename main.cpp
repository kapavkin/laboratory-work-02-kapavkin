#include "date.h"
#include "number.h"
#include "adam.h"
#include "matrix.h"

#include "array.h"
#include "stack.h"
#include "list.h"
#include "queue.h"
#include "tree.h"

#include "gtest/gtest.h"

namespace array_test
{
    TEST(array, constructor)
    {
        array arr0;
        array arr1(2);
        array arr2(arr0);
        array arr3(arr1);
    }

    TEST(array, insert)
    {
        array arr;

        date adt0;
        arr.insert(0, &adt0);

        ASSERT_EQ(arr[0], &adt0);

        date adt1;
        arr.insert(1, &adt1);

        ASSERT_EQ(arr[0], &adt0);
        ASSERT_EQ(arr[1], &adt1);

        number adt2;
        arr.insert(2, &adt2);

        ASSERT_EQ(arr[2], &adt2);

        adam adt3;
        arr.insert(0, &adt3);

        ASSERT_EQ(arr[0], &adt3);

        matrix adt4;
        arr.insert(2, &adt4);

        ASSERT_EQ(arr[2], &adt4);
    }

    TEST(array, erase)
    {
        array arr;

        date adt0;
        arr.insert(0, &adt0);

        date adt1;
        arr.insert(1, &adt1);

        number adt2;
        arr.insert(2, &adt2);

        adam adt3;
        arr.insert(0, &adt3);

        matrix adt4;
        arr.insert(2, &adt4);

        arr.erase(4);

        ASSERT_NE(arr[3], &adt2);

        arr.erase(0);

        ASSERT_NE(arr[0], &adt3);

        arr.erase(1);

        ASSERT_NE(arr[0], &adt4);
        ASSERT_NE(arr[1], &adt4);
    }
}

namespace stack_test
{
    TEST(stack, constructor)
    {
        stack st0;
        stack st1(2);
        stack st2(st0);
        stack st3(st1);
    }

    TEST(stack, push)
    {
        stack st;

        date adt0;
        st.push(&adt0);

        ASSERT_EQ(st[0], &adt0);

        date adt1;
        st.push(&adt1);

        ASSERT_EQ(st[0], &adt0);
        ASSERT_EQ(st[1], &adt1);

        number adt2;
        st.push(&adt2);

        ASSERT_EQ(st[2], &adt2);

        adam adt3;
        st.push(&adt3);

        ASSERT_EQ(st[3], &adt3);

        matrix adt4;
        st.push(&adt4);

        ASSERT_EQ(st[4], &adt4);
    }

    TEST(stack, pop)
    {
        stack st;

        date adt0;
        st.push(&adt0);

        ASSERT_EQ(st.pop(), &adt0);

        date adt1;
        st.push(&adt1);

        number adt2;
        st.push(&adt2);

        adam adt3;
        st.push(&adt3);

        matrix adt4;
        st.push(&adt4);

        ASSERT_EQ(st.pop(), &adt4);
        ASSERT_NE(st[2], &adt4);
    }
}

namespace list_test
{
    TEST(list, constructor)
    {
        list lst0;
        list lst1(lst0);
    }

    TEST(list, insert)
    {
        list lst;

        date adt0;
        lst.insert(0, &adt0);

        ASSERT_EQ(lst[0], &adt0);

        date adt1;
        lst.insert(1, &adt1);

        ASSERT_EQ(lst[0], &adt0);
        ASSERT_EQ(lst[1], &adt1);

        number adt2;
        lst.insert(2, &adt2);

        ASSERT_EQ(lst[2], &adt2);

        adam adt3;
        lst.insert(0, &adt3);

        ASSERT_EQ(lst[0], &adt3);

        matrix adt4;
        lst.insert(2, &adt4);

        ASSERT_EQ(lst[2], &adt4);
    }

    TEST(list, erase)
    {
        list lst;

        date adt0;
        lst.insert(0, &adt0);

        adam adt1;
        lst.insert(1, &adt1);

        number adt2;
        lst.insert(2, &adt2);

        adam adt3;
        lst.insert(0, &adt3);

        matrix adt4;
        lst.insert(2, &adt4);

        lst.erase(4);

        ASSERT_NE(lst[3], &adt2);

        lst.erase(0);

        ASSERT_NE(lst[0], &adt3);

        lst.erase(1);

        ASSERT_NE(lst[0], &adt4);
        ASSERT_NE(lst[1], &adt4);
    }
}

namespace queue_test
{
    TEST(queue, constructor)
    {
        queue q0(2);
        queue q1(q0);
    }

    TEST(queue, enqueue)
    {
        queue q(4);

        date adt0;
        q.enqueue(&adt0);

        ASSERT_EQ(q[0], &adt0);

        number adt1;
        q.enqueue(&adt1);

        ASSERT_EQ(q[0], &adt0);
        ASSERT_EQ(q[1], &adt1);

        adam adt2;
        q.enqueue(&adt2);

        ASSERT_EQ(q[2], &adt2);

        matrix adt3;
        q.enqueue(&adt3);

        ASSERT_EQ(q[3], &adt3);
    }

    TEST(queue, dequeue)
    {
        queue q(4);

        date adt0;
        q.enqueue(&adt0);

        number adt1;
        q.enqueue(&adt1);

        adam adt2;
        q.enqueue(&adt2);

        matrix adt3;
        q.enqueue(&adt3);

        ASSERT_EQ(q.dequeue(), &adt0);
        ASSERT_EQ(q[0], &adt1);

        ASSERT_EQ(q.dequeue(), &adt1);
        ASSERT_EQ(q[0], &adt2);

        ASSERT_EQ(q.dequeue(), &adt2);
        ASSERT_EQ(q[0], &adt3);

        ASSERT_EQ(q.dequeue(), &adt3);
    }

    TEST(queue, oversize)
    {
        queue q(4);

        date adt0;
        q.enqueue(&adt0);

        number adt1;
        q.enqueue(&adt1);

        adam adt2;
        q.enqueue(&adt2);

        q.dequeue();
        q.dequeue();

        matrix adt3;
        q.enqueue(&adt3);

        ASSERT_EQ(q[1], &adt3);

        date adt4;
        q.enqueue(&adt4);

        ASSERT_EQ(q[2], &adt4);

        number adt5;
        q.enqueue(&adt5);

        ASSERT_EQ(q[3], &adt5);

        ASSERT_EQ(q.dequeue(), &adt2);
        ASSERT_EQ(q[0], &adt3);

        ASSERT_EQ(q.dequeue(), &adt3);
        ASSERT_EQ(q[0], &adt4);

        ASSERT_EQ(q.dequeue(), &adt4);
    }
}

namespace tree_test
{
    TEST(tree, constructor)
    {
        tree tr0;
        tree tr1(tr0);
    }

    TEST(tree, insert)
    {
        tree tr;

        date adt0;
        tr.insert(0, &adt0);

        ASSERT_EQ(tr[0], &adt0);

        date adt1;
        tr.insert(1, &adt1);

        ASSERT_EQ(tr[0], &adt0);
        ASSERT_EQ(tr[1], &adt1);

        number adt2;
        tr.insert(2, &adt2);

        ASSERT_EQ(tr[2], &adt2);

        adam adt3;
        tr.insert(0, &adt3);

        ASSERT_EQ(tr[0], &adt3);

        matrix adt4;
        tr.insert(2, &adt4);

        ASSERT_EQ(tr[2], &adt4);
    }

    TEST(tree, erase)
    {
        tree tr;

        date adt0;
        tr.insert(0, &adt0);

        adam adt1;
        tr.insert(1, &adt1);

        number adt2;
        tr.insert(2, &adt2);

        adam adt3;
        tr.insert(0, &adt3);

        matrix adt4;
        tr.insert(2, &adt4);

        tr.erase(4);

        ASSERT_NE(tr[3], &adt2);

        tr.erase(0);

        ASSERT_NE(tr[0], &adt3);

        tr.erase(1);

        ASSERT_NE(tr[0], &adt4);
        ASSERT_NE(tr[1], &adt4);
    }
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

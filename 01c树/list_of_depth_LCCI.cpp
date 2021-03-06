/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/**
*
*����˼·��
*1.��������buf���ڴ��ÿһ���������ͷ������curr���ڴ������ǰ�Ľ��
*2.��һ�α���ʱ���洢����flag=0,���洢����رգ������д洢���������������������*returnSize
*3.Ϊbuf����Ϊ*returnSzie�Ķ�̬�ڴ棬��������Ϊstruct ListNode *
*4.Ϊcurr����Ϊ*returnSzie�Ķ�̬�ڴ棬��������Ϊstruct ListNode *����ͬʱ��ʼ���ڴ棬��֤bufԪ��
* ָ��curr��ÿ��Ԫ�أ�
*5.�ڶ��α����������������洢���أ���flag=1,ÿ������һ�������ڴ棬�������ӵ�curr[ depth ]��
*  ���棬ͬʱ����curr[ depth ]ָ��ָ���λ��
*6.�����ӽڵ㣬
*7.Ϊ�˼����жϵĲ��裬����û�ж�ÿ������ͷ�������κ����ݣ�����ʵ���ϴ�ʱbuf[ depth ] -> val
*  ȫ�����룬������Ҫ����ͷ��㣬���ͷžɵĽ��
*/

/**
*Function: visiting the binary tree and saving the value of nodes to link according to flag
*param: struct TreeNode * t : current node in bianry tree
*param: int depth : the depth of current node
*param: int * returnSize : the maximun of depth in the bianry tree
*param: int flag : determining whether to save the value of nodes: 0 : no , 1 : yes
*param: struct ListNode ** curr : current node of each links
*Return: void
*/
void visitTree( struct TreeNode * t , int depth , int * returnSize , 
                                    int flag , struct ListNode ** curr )
{
    
    //if current node is NULL in the binary tree, returning void
    if( t == NULL )
    {

        return ;

    }

    //saving the value of current node to depthth link
    if( flag == 1 )
    {

        //alloclating memory to new node in depthth link
        struct ListNode * tmp = ( struct ListNode * )malloc( sizeof( struct ListNode ) * 1 );
        curr[ depth ] -> next = tmp;
        curr[ depth ] = tmp;
        tmp -> val = t -> val;
        tmp -> next = NULL;


    } else 
    {
        
        //only calculating the maximun depth in the binary tree
        *returnSize = *returnSize > depth ? *returnSize : depth;

    }

    //visiting the left and right child int the binary tree
    visitTree( t -> left , depth + 1 , returnSize , flag , curr );
    visitTree( t -> right , depth + 1 , returnSize , flag , curr );

}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct ListNode ** listOfDepth( struct TreeNode * tree , int * returnSize )
{

    //declearing parameter of buf and curr
    struct ListNode ** buf;
    struct ListNode ** curr;

    //intializing the value of *returnSize
    *returnSize = 0;
    visitTree( tree , 1 , returnSize , 0 , curr );

    //alloclating memory to save the header of each link and current nodes in each link
    buf = ( struct ListNode ** )malloc( sizeof( struct ListNode * ) * ( *returnSize ) );
    curr =( struct ListNode ** )malloc( sizeof( struct ListNode * ) * ( *returnSize ) );

    for( int i = 0 ; i < *returnSize ; i++ )
    {
        
        //intializing the meomry of buf and curr
        *( curr + i ) = ( struct ListNode * )malloc( sizeof( struct ListNode ) * 1 );
        buf[ i ] = curr[ i ];
        curr[ i ] -> next = NULL;
        curr[ i ] -> val = INT_MIN;

    }

    visitTree( tree , 0 , returnSize , 1 , curr );

    //deleting the header of link, updating the header
    for( int i = 0 ; i < *returnSize ; i++ )
    {

        struct ListNode * tmp = buf[ i ];
        buf[ i ] = buf[ i ] -> next;
        free( tmp );

    }

    //freeing the memory of curr
    free( curr );
    return buf;
}
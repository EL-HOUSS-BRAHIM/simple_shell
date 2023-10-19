#include "shell.h"
/**
 * add_comment - Add a comment to the comment list.
 * @comment_list: A pointer to the comment list.
 * @text: The text of the comment.
 */
void add_comment(Comment **comment_list, char *text)
{
Comment *new_comment, *temp;
new_comment = malloc(sizeof(Comment));
if (!new_comment)
{
fprintf(stderr, "add_comment: memory allocation error\n");
return;
}
new_comment->text = strdup(text);
if (!new_comment->text)
{
fprintf(stderr, "add_comment: memory allocation error\n");
free(new_comment);
return;
}
new_comment->next = NULL;
if (*comment_list == NULL)
{
*comment_list = new_comment;
return;
}
temp = *comment_list;
while (temp->next)
temp = temp->next;
temp->next = new_comment;
}
/**
 * print_comments - Print the list of comments.
 * @comment_list: The list of comments.
 */
void print_comments(Comment *comment_list)
{
Comment *temp = comment_list;
while (temp)
{
printf("%s\n", temp->text);
temp = temp->next;
}
}
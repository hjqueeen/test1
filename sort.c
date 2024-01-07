//#include "sort.h"
//#include "myPointerList.h"
//
//// if data of Listitem is interger
//
//void sortBubble(List *list) {
//    if (list == NULL) {
//        exit(1);
//    }
//
//    ListItem *i, *j;
//    void *temp;
//
//    for (i = list->first; i != NULL; i = i->next) {
//        for (j = i; j != NULL; j = j->next) {
//            if (*((int *) i->data) > *((int *) j->data)) {
//                temp = i->data;
//                i->data = j->data;
//                j->data = temp;
//            }
//        }
//    }
//}
//

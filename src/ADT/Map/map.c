// #include <stdio.h>
// #include "map.h"

// /* ********* Predikat Untuk test keadaan KOLEKSI ********* */
// boolean IsEmptyMap(Map M){
//     return (M.Count == Nil);
// }
// /* Mengirim true jika Map M kosong*/
// /* Ciri Map kosong : count bernilai Nil */

// boolean IsFullMap(Map M){
//     return (M.Count == MaxEl);
// }
// /* Mengirim true jika Album M penuh */
// /* Ciri Map penuh : count bernilai MaxEl */

// /* ********** Operator Dasar Map ********* */
// valuetype Song(Map M, keytype *k){
//     int i = 0;
//     boolean found = false; 
//     while ( !(found) && i < M.Count){
//         if (IsSameString(M.Elements[i].key, k)){
//             found = true;
//         }else{
//             i++;
//         }
//     }
//     if (found){
//         return (M.Elements[i].song);
//     }
//     // else{
//     //     return (-9999);
//     // }
// }
// /* Mengembalikan lagu dengan album k dari M */
// /* Jika tidak ada album k pada M, akan mengembalikan Undefined */

// boolean IsMember(Map M, keytype *k){
//     int i;
//     for (i = 0; i < M.Count; i++){
//         if (IsSameString(M.Elements[i].key, k)){
//             return true;
//         }
//     }
//     return false;
// }
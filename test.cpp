
#include <iostream>

//                             1
//           / | block[0] | block[1] | block[2] | \
//         0   | block[3] |          | block[4] | 2
//           \ | block[5] | block[6] | block[7] | /  
//                             3

bool leftMethod(int* block, int* deliveryOrder, int startPosition);
bool rightMethod(int* block, int* deliveryOrder, int startPosition);
bool sameColorLeftMethod(int* block, int* deliveryOrder, int startPosition);
bool sameColorRightMethod(int* block, int* deliveryOrder, int startPosition);

int main(){

    int t_currentPosition = 1;
    int t_block[8] = {0,0,1,1,2,2,3,3};
    int t_delivery[8];
    bool t_result;

    int counter = 0;
    do{
        t_result = sameColorLeftMethod(&t_block[0], &t_delivery[0], t_currentPosition);
        if (t_result == false)
            t_result = sameColorRightMethod(&t_block[0], &t_delivery[0], t_currentPosition);
        if (t_result == false)
            t_result = leftMethod(&t_block[0], &t_delivery[0], t_currentPosition);
        if (t_result == false)
            t_result = rightMethod(&t_block[0], &t_delivery[0], t_currentPosition);
        if (t_result == true)
            counter++;
    }while(std::next_permutation(t_block,t_block+8));

    std::cout << counter << "/2520 Clear!" << std::endl;

    return 0;
}


bool leftMethod(int* block, int* deliveryOrder, int startPosition){

    /* startPositon を currentPositon に設定する */
    int currentPosition = startPosition;
    int deliveredFlag[8] = {0,0,0,0,0,0,0,0};
    bool result = true;

    for (int i=0; i<8; i++){
        if(currentPosition == 0){
            if(deliveredFlag[3] == 0){
                deliveredFlag[3] = 1;
                currentPosition = block[3];
                deliveryOrder[i] = 3;
            }else if(deliveredFlag[0] == 0){
                deliveredFlag[0] = 1;
                currentPosition = block[0];
                deliveryOrder[i] = 0;
            }else if(deliveredFlag[5] == 0){
                deliveredFlag[5] = 1;
                currentPosition = block[5];
                deliveryOrder[i] = 5;
            }else{
                result = false;
                break;
            }
        }else if(currentPosition == 1){
            if(deliveredFlag[1] == 0){
                deliveredFlag[1] = 1;
                currentPosition = block[1];
                deliveryOrder[i] = 1;
            }else if(deliveredFlag[2] == 0){
                deliveredFlag[2] = 1;
                currentPosition = block[2];
                deliveryOrder[i] = 2;
            }else if(deliveredFlag[0] == 0){
                deliveredFlag[0] = 1;
                currentPosition = block[0];
                deliveryOrder[i] = 0;
            }else{
                result = false;
                break;
            }
        }else if(currentPosition == 2){
            if(deliveredFlag[4] == 0){
                deliveredFlag[4] = 1;
                currentPosition = block[4];
                deliveryOrder[i] = 4;
            }else if(deliveredFlag[7] == 0){
                deliveredFlag[7] = 1;
                currentPosition = block[7];
                deliveryOrder[i] = 7;
            }else if(deliveredFlag[2] == 0){
                deliveredFlag[2] = 1;
                currentPosition = block[2];
                deliveryOrder[i] = 2;
            }else{
                result = false;
                break;
            }
        }else if(currentPosition == 3){
            if(deliveredFlag[6] == 0){
                deliveredFlag[6] = 1;
                currentPosition = block[6];
                deliveryOrder[i] = 6;
            }else if(deliveredFlag[5] == 0){
                deliveredFlag[5] = 1;
                currentPosition = block[5];
                deliveryOrder[i] = 5;
            }else if(deliveredFlag[7] == 0){
                deliveredFlag[7] = 1;
                currentPosition = block[7];
                deliveryOrder[i] = 7;
            }else{
                result = false;
                break;
            }
        }
    }

    return result;
}


bool rightMethod(int* block, int* deliveryOrder, int startPosition){

    /* startPositon を currentPositon に設定する */
    int currentPosition = startPosition;
    int deliveredFlag[8] = {0,0,0,0,0,0,0,0};
    bool result = true;

    for (int i=0; i<8; i++){
        if(result == false){ /* 失敗したときもブロックリストが作成できるようなバックアップ */
            for(int j=0; j<8; j++){
                if(deliveredFlag[j] == 0){
                    deliveredFlag[j] = 1;
                    deliveryOrder[i] = j;
                    break;
                }
            }
        }else if(currentPosition == 0){
            if(deliveredFlag[3] == 0){
                deliveredFlag[3] = 1;
                currentPosition = block[3];
                deliveryOrder[i] = 3;
            }else if(deliveredFlag[5] == 0){
                deliveredFlag[5] = 1;
                currentPosition = block[5];
                deliveryOrder[i] = 5;
            }else if(deliveredFlag[0] == 0){
                deliveredFlag[0] = 1;
                currentPosition = block[0];
                deliveryOrder[i] = 0;
            }else{
                result = false;
            }
        }else if(currentPosition == 1){
            if(deliveredFlag[1] == 0){
                deliveredFlag[1] = 1;
                currentPosition = block[1];
                deliveryOrder[i] = 1;
            }else if(deliveredFlag[0] == 0){
                deliveredFlag[0] = 1;
                currentPosition = block[0];
                deliveryOrder[i] = 0;
            }else if(deliveredFlag[2] == 0){
                deliveredFlag[2] = 1;
                currentPosition = block[2];
                deliveryOrder[i] = 2;
            }else{
                result = false;
            }
        }else if(currentPosition == 2){
            if(deliveredFlag[4] == 0){
                deliveredFlag[4] = 1;
                currentPosition = block[4];
                deliveryOrder[i] = 4;
            }else if(deliveredFlag[2] == 0){
                deliveredFlag[2] = 1;
                currentPosition = block[2];
                deliveryOrder[i] = 2;
            }else if(deliveredFlag[7] == 0){
                deliveredFlag[7] = 1;
                currentPosition = block[7];
                deliveryOrder[i] = 7;
            }else{
                result = false;
            }
        }else if(currentPosition == 3){
            if(deliveredFlag[6] == 0){
                deliveredFlag[6] = 1;
                currentPosition = block[6];
                deliveryOrder[i] = 6;
            }else if(deliveredFlag[7] == 0){
                deliveredFlag[7] = 1;
                currentPosition = block[7];
                deliveryOrder[i] = 7;
            }else if(deliveredFlag[5] == 0){
                deliveredFlag[5] = 1;
                currentPosition = block[5];
                deliveryOrder[i] = 5;
            }else{
                result = false;
            }
        }
    }

    return result;
}


bool sameColorLeftMethod(int* block, int* deliveryOrder, int startPosition){

    /* startPositon を currentPositon に設定する */
    int currentPosition = startPosition;
    int deliveredFlag[8] = {0,0,0,0,0,0,0,0};
    bool result = true;

    for (int i=0; i<8; i++){
        if(currentPosition == 0){
            if(block[3] == 0 && deliveredFlag[3] == 0){
                deliveredFlag[3] = 1;
                currentPosition = block[3];
                deliveryOrder[i] = 3;
            }else if(block[0] == 0 && deliveredFlag[0] == 0){
                deliveredFlag[0] = 1;
                currentPosition = block[0];
                deliveryOrder[i] = 0;
            }else if(block[5] == 0 && deliveredFlag[5] == 0){
                deliveredFlag[5] = 1;
                currentPosition = block[5];
                deliveryOrder[i] = 5;
            }else if(deliveredFlag[3] == 0){
                deliveredFlag[3] = 1;
                currentPosition = block[3];
                deliveryOrder[i] = 3;
            }else if(deliveredFlag[0] == 0){
                deliveredFlag[0] = 1;
                currentPosition = block[0];
                deliveryOrder[i] = 0;
            }else if(deliveredFlag[5] == 0){
                deliveredFlag[5] = 1;
                currentPosition = block[5];
                deliveryOrder[i] = 5;
            }else{
                result = false;
                break;
            }
        }else if(currentPosition == 1){
            if(block[1] == 1 && deliveredFlag[1] == 0){
                deliveredFlag[1] = 1;
                currentPosition = block[1];
                deliveryOrder[i] = 1;
            }else if(block[2] == 1 && deliveredFlag[2] == 0){
                deliveredFlag[2] = 1;
                currentPosition = block[2];
                deliveryOrder[i] = 2;
            }else if(block[0] == 1 && deliveredFlag[0] == 0){
                deliveredFlag[0] = 1;
                currentPosition = block[0];
                deliveryOrder[i] = 0;
            }else if(deliveredFlag[1] == 0){
                deliveredFlag[1] = 1;
                currentPosition = block[1];
                deliveryOrder[i] = 1;
            }else if(deliveredFlag[2] == 0){
                deliveredFlag[2] = 1;
                currentPosition = block[2];
                deliveryOrder[i] = 2;
            }else if(deliveredFlag[0] == 0){
                deliveredFlag[0] = 1;
                currentPosition = block[0];
                deliveryOrder[i] = 0;
            }else{
                result = false;
                break;
            }
        }else if(currentPosition == 2){
            if(block[4] == 2 && deliveredFlag[4] == 0){
                deliveredFlag[4] = 1;
                currentPosition = block[4];
                deliveryOrder[i] = 4;
            }else if(block[7] == 2 && deliveredFlag[7] == 0){
                deliveredFlag[7] = 1;
                currentPosition = block[7];
                deliveryOrder[i] = 7;
            }else if(block[2] == 2 && deliveredFlag[2] == 0){
                deliveredFlag[2] = 1;
                currentPosition = block[2];
                deliveryOrder[i] = 2;
            }else if(deliveredFlag[4] == 0){
                deliveredFlag[4] = 1;
                currentPosition = block[4];
                deliveryOrder[i] = 4;
            }else if(deliveredFlag[7] == 0){
                deliveredFlag[7] = 1;
                currentPosition = block[7];
                deliveryOrder[i] = 7;
            }else if(deliveredFlag[2] == 0){
                deliveredFlag[2] = 1;
                currentPosition = block[2];
                deliveryOrder[i] = 2;
            }else{
                result = false;
                break;
            }
        }else if(currentPosition == 3){
            if(block[6] == 3 && deliveredFlag[6] == 0){
                deliveredFlag[6] = 1;
                currentPosition = block[6];
                deliveryOrder[i] = 6;
            }else if(block[5] == 3 && deliveredFlag[5] == 0){
                deliveredFlag[5] = 1;
                currentPosition = block[5];
                deliveryOrder[i] = 5;
            }else if(block[7] == 3 && deliveredFlag[7] == 0){
                deliveredFlag[7] = 1;
                currentPosition = block[7];
                deliveryOrder[i] = 7;
            }else if(deliveredFlag[6] == 0){
                deliveredFlag[6] = 1;
                currentPosition = block[6];
                deliveryOrder[i] = 6;
            }else if(deliveredFlag[5] == 0){
                deliveredFlag[5] = 1;
                currentPosition = block[5];
                deliveryOrder[i] = 5;
            }else if(deliveredFlag[7] == 0){
                deliveredFlag[7] = 1;
                currentPosition = block[7];
                deliveryOrder[i] = 7;
            }else{
                result = false;
                break;
            }
        }
    }

    return result;
}

bool sameColorRightMethod(int* block, int* deliveryOrder, int startPosition){

    /* startPositon を currentPositon に設定する */
    int currentPosition = startPosition;
    int deliveredFlag[8] = {0,0,0,0,0,0,0,0};
    bool result = true;

    for (int i=0; i<8; i++){
        if(currentPosition == 0){
            if(block[3] == 0 && deliveredFlag[3] == 0){
                deliveredFlag[3] = 1;
                currentPosition = block[3];
                deliveryOrder[i] = 3;
            }else if(block[5] == 0 && deliveredFlag[5] == 0){
                deliveredFlag[5] = 1;
                currentPosition = block[5];
                deliveryOrder[i] = 5;
            }else if(block[0] == 0 && deliveredFlag[0] == 0){
                deliveredFlag[0] = 1;
                currentPosition = block[0];
                deliveryOrder[i] = 0;
            }else if(deliveredFlag[3] == 0){
                deliveredFlag[3] = 1;
                currentPosition = block[3];
                deliveryOrder[i] = 3;
            }else if(deliveredFlag[5] == 0){
                deliveredFlag[5] = 1;
                currentPosition = block[5];
                deliveryOrder[i] = 5;
            }else if(deliveredFlag[0] == 0){
                deliveredFlag[0] = 1;
                currentPosition = block[0];
                deliveryOrder[i] = 0;
            }else{
                result = false;
                break;
            }
        }else if(currentPosition == 1){
            if(block[1] == 1 && deliveredFlag[1] == 0){
                deliveredFlag[1] = 1;
                currentPosition = block[1];
                deliveryOrder[i] = 1;
            }else if(block[0] == 1 && deliveredFlag[0] == 0){
                deliveredFlag[0] = 1;
                currentPosition = block[0];
                deliveryOrder[i] = 0;
            }else if(block[2] == 1 && deliveredFlag[2] == 0){
                deliveredFlag[2] = 1;
                currentPosition = block[2];
                deliveryOrder[i] = 2;
            }else if(deliveredFlag[1] == 0){
                deliveredFlag[1] = 1;
                currentPosition = block[1];
                deliveryOrder[i] = 1;
            }else if(deliveredFlag[0] == 0){
                deliveredFlag[0] = 1;
                currentPosition = block[0];
                deliveryOrder[i] = 0;
            }else if(deliveredFlag[2] == 0){
                deliveredFlag[2] = 1;
                currentPosition = block[2];
                deliveryOrder[i] = 2;
            }else{
                result = false;
                break;
            }
        }else if(currentPosition == 2){
            if(block[4] == 2 && deliveredFlag[4] == 0){
                deliveredFlag[4] = 1;
                currentPosition = block[4];
                deliveryOrder[i] = 4;
            }else if(block[2] == 2 && deliveredFlag[2] == 0){
                deliveredFlag[2] = 1;
                currentPosition = block[2];
                deliveryOrder[i] = 2;
            }else if(block[7] == 2 && deliveredFlag[7] == 0){
                deliveredFlag[7] = 1;
                currentPosition = block[7];
                deliveryOrder[i] = 7;
            }else if(deliveredFlag[4] == 0){
                deliveredFlag[4] = 1;
                currentPosition = block[4];
                deliveryOrder[i] = 4;
            }else if(deliveredFlag[2] == 0){
                deliveredFlag[2] = 1;
                currentPosition = block[2];
                deliveryOrder[i] = 2;
            }else if(deliveredFlag[7] == 0){
                deliveredFlag[7] = 1;
                currentPosition = block[7];
                deliveryOrder[i] = 7;
            }else{
                result = false;
                break;
            }
        }else if(currentPosition == 3){
            if(block[6] == 3 && deliveredFlag[6] == 0){
                deliveredFlag[6] = 1;
                currentPosition = block[6];
                deliveryOrder[i] = 6;
            }else if(block[7] == 3 && deliveredFlag[7] == 0){
                deliveredFlag[7] = 1;
                currentPosition = block[7];
                deliveryOrder[i] = 7;
            }else if(block[5] == 3 && deliveredFlag[5] == 0){
                deliveredFlag[5] = 1;
                currentPosition = block[5];
                deliveryOrder[i] = 5;
            }else if(deliveredFlag[6] == 0){
                deliveredFlag[6] = 1;
                currentPosition = block[6];
                deliveryOrder[i] = 6;
            }else if(deliveredFlag[7] == 0){
                deliveredFlag[7] = 1;
                currentPosition = block[7];
                deliveryOrder[i] = 7;
            }else if(deliveredFlag[5] == 0){
                deliveredFlag[5] = 1;
                currentPosition = block[5];
                deliveryOrder[i] = 5;
            }else{
                result = false;
                break;
            }
        }
    }

    return result;
}

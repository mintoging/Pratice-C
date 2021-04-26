#include <stdio.h>

int main()
{
    int frame[10][3] = { 0, };
    int frame10[4] = { 0, };
    int frameScore[11] = { 0, };
    int i;

    for (i = 1; i <= 9; ++i)
    {
        while (1)
        {
            printf("%d game first score : ", i);
            scanf("%d", &frame[i][1]);
            if (frame[i][1] < 0 || frame[i][1] > 10)
                printf("Error! input number\n");
            else
                break;
        }
        //전 프레임에서 스페어를 한 경우
        if (i > 1 && frame[i - 1][1] + frame[i - 1][2] == 10 && frame[i - 1][1] != 10)
        {
            frameScore[i - 1] = frameScore[i - 2] + 10 + frame[i][1];
            printf("%d frame Score : %d\n", i - 1, frameScore[i - 1]);
        }
        //전 프레임, 전전 프레임이 스트라이크인 경우
        if (i > 2 && frame[i - 2][1] == 10 && frame[i - 1][1] == 10)
        {
            frameScore[i - 2] = frameScore[i - 3] + 20 + frame[i][1];
            printf("%d frame Score : %d\n", i - 2, frameScore[i - 2]);
        }

        if (frame[i][1] != 10)
        {
            while (1)
            {
                printf("%d game second score : ", i);
                scanf("%d", &frame[i][2]);
                if (frame[i][2] < 0 || frame[i][2] > 10)
                    printf("Error! input number\n");
                else if (frame[i][1] + frame[i][2] > 10)
                    printf("Too much input number!\n");
                else
                    break;
            }

            //전 프레임이 스트라이크인가?
            if (i > 1 && frame[i - 1][1] == 10)
            {
                frameScore[i - 1] = frameScore[i - 2] + 10 + frame[i][1] + frame[i][2];
                printf("%d frame Score : %d\n", i - 1, frameScore[i - 1]);
            }
            //스페어를 하지 못했나?
            if (frame[i][1] + frame[i][2] < 10)
            {
                frameScore[i] = frameScore[i - 1] + frame[i][1] + frame[i][2];
                printf("%d frame Score : %d\n", i, frameScore[i]);
            }
        }
    }

    //10 프레임//
    //첫번째 투구
    while (1)
    {
        printf("%d game first score : ", 10);
        scanf("%d", &frame10[1]);
        if (frame10[1] < 0 || frame10[1] > 10)
            printf("Error! input number\n");
        else
            break;
    }
    //전 프레임이 스페어인가?
    if (frame[i][1] + frame[i][2] == 10 && frame10[1] != 10)
    {
        frameScore[i - 1] = frameScore[i - 2] + 10 + frame10[1];
        printf("%d frame Score : %d\n", i - 1, frameScore[i - 1]);
    }
    //전전 프레임과 전 프레임이 스트라이크인가?
    else if (frame[i - 2][1] == 10 && frame[i - 1][1] == 10)
    {
        frameScore[i - 2] = frameScore[i - 3] + 20 + frame10[1];
        printf("%d frame Score : %d\n", i - 2, frameScore[i - 2]);
    }

    //두번째 투구
    if (frame10[1] == 10)
        while (1)
        {
            printf("%d game second score : ", 10);
            scanf("%d", &frame10[2]);
            if (frame10[2] < 0 || frame10[2] > 10)
                printf("Error! input number\n");
            else
                break;
        }
    else
        while (1)
        {
            printf("%d game second score : ", 10);
            scanf("%d", &frame10[2]);
            if (frame10[2] < 0 || frame10[2] > 10)
                printf("Error! input number\n");
            else if (frame10[1] + frame10[2] > 10)
                printf("Too much input number!\n");
            else
                break;
        }

    if (frame[i - 1][1] == 10)
    {
        frameScore[i - 1] = frameScore[i - 2] + 10 + frame10[1] + frame10[2];
        printf("%d frame Score : %d\n", i - 1, frameScore[i - 1]);
    }

    if (frame10[1] + frame10[2] >= 10)
        while (1)
        {
            printf("%d game third score : ", 10);
            scanf("%d", &frame10[3]);
            if (frame10[3] < 0 || frame10[3] > 10)
                printf("Error! input number\n");
            else
                break;
        }
    frameScore[10] = frameScore[i - 1] + frame10[1] + frame10[2] + frame10[3];
    printf("%d frame Score : %d\n", 10, frameScore[10]);
    return 0;
}
struct MoveData
{
	short move_x;
	short move_y;
};

struct MoveInfo
{
	int move_count;
	MoveData* d1;
};

void InitMonsterMove(const char* str);
void EnemyMoveInput(int p_iCnt);
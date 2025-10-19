struct student {
	int number, score;
	char *name;
};

struct teacher {
	int number, salary;
	char *name;
};

struct cls {
	int number;
	struct student students[3];
	struct teacher teacher[5];
	struct teacher *advisor;
};

int main (){
	struct cls classes[5];
	int i;
	classes[1].students[1].score = 1;
    i = classes[1].students[1].score;
	output i;
    return 0;
}
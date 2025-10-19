struct student {
	int number;
	int score;
};

struct teacher {
	int number;
	int is_advisor;
};

struct class {
	int number;                  
	struct student students[5]; 
	struct teacher teacher[2];   
	struct teacher *advisor;     
};

void init_teacher(struct teacher &t, int teacher_number, int is_advisor) {
	t.number = teacher_number;
	t.is_advisor = is_advisor;
	output "teacher "; 
	output teacher_number; 
	output " inited, ";
	if (is_advisor) {
		output "is advisor";
	}
	else {
		output "is not advisor";
	}
	output "\n";
}

void init_class(struct class &c, int class_number, struct teacher *advisor) {
	int advisor_number;
	advisor_number = advisor->number;
    c.number = class_number;
    c.advisor = advisor;
	output "class "; 
	output class_number; 
	output " inited, advisor number: ";
	output advisor_number;
	output "\n";
}

void init_student(struct student &s, int student_number, int score, struct class &c) {
	int class_number;
	class_number = c.number;
    s.number = student_number;
    s.score = score;
	output "student ";
	output student_number; 
	output " inited, belongs to class ";
	output class_number; 
	output "\n";
}

void judge_student(struct student &s){
	int student_number, score;
	student_number = s.number;
	score = s.score;
	output "student ";
	output student_number; 
	output "'s score is ";
	output score; 
	if (score < 60) {
		output ". A bad student!";
	}
	else {
		output ". A good student!";
	}
	output "\n";
}

int main() {
	int i;
	struct class class1;
	struct teacher advisor, teacher_math, teacher_chinese;
	advisor.number = 10;
	init_teacher(advisor, 1, 1);
	init_teacher(teacher_math, 2, 0);
	init_teacher(teacher_chinese, 3, 0);
	init_class(class1, 10, &advisor);

	for (i = 0; i < 5; i = i + 1){
		init_student(class1.students[i], i, i*20, class1);
	}
	for (i = 0; i < 5; i = i + 1){
		judge_student(class1.students[i]);
	}

	class1.students[10].number = 1;
	return 0;
}
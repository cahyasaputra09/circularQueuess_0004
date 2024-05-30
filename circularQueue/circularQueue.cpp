#include <iostream>
using namespace std;

class Queues {
	int FRONT, REAR, max = 5;
	int queue_array[5];

public:
	Queues() {
		FRONT = -1;
		REAR = -1;
	}

	void insert() {
		int num;
		cout << "Enter a number : ";
		cin >> num;
		cout << endl;

		if ((FRONT == 0 && REAR == max - 1) || (FRONT == REAR + 1)) {
			cout << "\nQueue overFlow\n";
			return;
		}

		if (FRONT == -1) {
			FRONT = 0;
			REAR = 0;
		}
		else {

			if (REAR == max - 1)
				REAR = 0;
			else
				REAR = REAR + 1;
		}
		queue_array[REAR] = num;
	}

	void remove() {
		//cek apakah antrian kosong
		if (FRONT == -1) {
			cout << "Queue underflow\n";
			return;
		}
		cout << "\nlement deleted from the Queue is : " << queue_array[FRONT] << "\n";

			//cek jika antrian hanya memiliki satu elemen
			if (FRONT == REAR) {
				FRONT = -1;
				REAR = -1;
			}
			else {
				//jika elemen yang di hapus berada di posos terakhir array, kembali ke awal array
				if (FRONT == max - 1)
					FRONT == 0;
				else
					FRONT = FRONT + 1;
			}
	}
	void display() {
		int FRONT_postition = FRONT;
		int REAR_postition = FRONT;

		//cek apakah antrian kosong
		if (FRONT == -1) {
			cout << "Queue is empty\n";
			return;
		}

		cout << "\nElements in the Queue are ...\n";

		// jika FRONT_poostition <= REAR_postition, iterai dari FRONT hingga REAR
		if (FRONT_postition <= REAR_postition) {
			while (FRONT_postition <= REAR_postition) {
				cout << queue_array[FRONT_postition] << " ";
				FRONT_postition++;
			}
			cout << endl;
		}
		else {
			//jika FRONT_postition >REAR_postition, iterasi dari FRONT hingga akhri array
			while (FRONT_postition <= max - 1) {
				cout << queue_array[FRONT_postition] << " ";
				FRONT_postition++;
			}

			FRONT_postition = 0;

			//literasi dari awal array hingga REAR
			while (FRONT_postition <= REAR_postition) {
				cout << queue_array[FRONT_postition] << " ";
				FRONT_postition++;
			}
			cout << endl;
		}
	}
};
int main() {
	Queues q;
	char ch;

	while (true) {
		try {
			cout << "Menu" << endl;
			cout << "1. Implement insert operation" << endl;
			cout << "2. Implement Delete Operation" << endl;
			cout << "3. Display values " << endl;
			cout << "4. Exit " << endl;
			cout << "Enter your choice (1-4): ";
			cin >> ch;
			cout << endl;

			switch (ch) {
			case '1': {

				q.insert();
				break;
			}
			case '2': {
				q.remove();
				break;
			}
			case '3': {
				q.display();
				break;
			}
			case '4': {
				return 0;
			}
			default: {
				cout << "Invalid option!!!" << endl;
				break;




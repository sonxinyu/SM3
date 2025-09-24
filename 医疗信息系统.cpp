#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ���廼����Ϣ�ṹ��
typedef struct Patient {
    char name[20];
    char id[25];
    char gender[10];
    int age;
    char contact[20];
    struct Patient* next;
} Patient;

// ����ҽ����Ϣ�ṹ��
typedef struct Doctor {
    char name[20];
    char id[25];
    char specialty[20];
    char title[20];
    char schedule[50];
    struct Doctor* next;
} Doctor;

// ����Һ���Ϣ�ṹ��
typedef struct Appointment {
    char patientName[20];
    char doctorName[20];
    char date[20];
    float fee;
    struct Appointment* next;
} Appointment;

// ���岡����Ϣ�ṹ��
typedef struct MedicalRecord {
    int recordId;
    char patientName[20];
    char content[200];
    struct MedicalRecord* next;
} MedicalRecord;

// ����ҩƷ�����Ϣ�ṹ��
typedef struct MedicineStock {
    char medicineName[50];
    int quantity;
    float purchasePrice;
    struct MedicineStock* next;
} MedicineStock;

// ����ҩƷ������Ϣ�ṹ��
typedef struct MedicineSale {
    char medicineName[50];
    int saleQuantity;
    float salePrice;
    char saleDate[20];
    struct MedicineSale* next;
} MedicineSale;

// ������ͷ��ָ��
Patient* patientHead = NULL;
Doctor* doctorHead = NULL;
Appointment* appointmentHead = NULL;
MedicalRecord* medicalRecordHead = NULL;
MedicineStock* medicineStockHead = NULL;
MedicineSale* medicineSaleHead = NULL;

// ��������
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// ��ͣ����
void pause() {
    printf("\n���س�������...");
    getchar();
    getchar();
}

// ���滼����Ϣ���ļ�
void savePatients() {
    FILE* file = fopen("patients.txt", "wb");
    if (file == NULL) {
        printf("�޷����ļ����滼����Ϣ��\n");
        return;
    }
    Patient* current = patientHead;
    while (current != NULL) {
        fwrite(current, sizeof(Patient), 1, file);
        current = current->next;
    }
    fclose(file);
}

// ���ػ�����Ϣ���ļ�
void loadPatients() {
    FILE* file = fopen("patients.txt", "r");
    if (file == NULL) {
        return;
    }
    Patient* newPatient;
    while (1) {
        newPatient = (Patient*)malloc(sizeof(Patient));
        if (fread(newPatient, sizeof(Patient), 1, file) != 1) {
            free(newPatient);
            break;
        }
        newPatient->next = patientHead;
        patientHead = newPatient;
    }
    fclose(file);
}

// ����ҽ����Ϣ���ļ�
void saveDoctors() {
    FILE* file = fopen("doctors.txt", "wb");
    if (file == NULL) {
        printf("�޷����ļ�����ҽ����Ϣ��\n");
        return;
    }
    Doctor* current = doctorHead;
    while (current != NULL) {
        fwrite(current, sizeof(Doctor), 1, file);
        current = current->next;
    }
    fclose(file);
}

// ����ҽ����Ϣ���ļ�
void loadDoctors() {
    FILE* file = fopen("doctors.txt", "r");
    if (file == NULL) {
        return;
    }
    Doctor* newDoctor;
    while (1) {
        newDoctor = (Doctor*)malloc(sizeof(Doctor));
        if (fread(newDoctor, sizeof(Doctor), 1, file) != 1) {
            free(newDoctor);
            break;
        }
        newDoctor->next = doctorHead;
        doctorHead = newDoctor;
    }
    fclose(file);
}

// ����Һ���Ϣ���ļ�
void saveAppointments() {
    FILE* file = fopen("appointments.txt", "wb");
    if (file == NULL) {
        printf("�޷����ļ�����Һ���Ϣ��\n");
        return;
    }
    Appointment* current = appointmentHead;
    while (current != NULL) {
        fwrite(current, sizeof(Appointment), 1, file);
        current = current->next;
    }
    fclose(file);
}

// ���عҺ���Ϣ���ļ�
void loadAppointments() {
    FILE* file = fopen("appointments.txt", "r");
    if (file == NULL) {
        return;
    }
    Appointment* newAppointment;
    while (1) {
        newAppointment = (Appointment*)malloc(sizeof(Appointment));
        if (fread(newAppointment, sizeof(Appointment), 1, file) != 1) {
            free(newAppointment);
            break;
        }
        newAppointment->next = appointmentHead;
        appointmentHead = newAppointment;
    }
    fclose(file);
}

// ���没����Ϣ���ļ�
void saveMedicalRecords() {
    FILE* file = fopen("medicalRecords.txt", "wb");
    if (file == NULL) {
        printf("�޷����ļ����没����Ϣ��\n");
        return;
    }
    MedicalRecord* current = medicalRecordHead;
    while (current != NULL) {
        fwrite(current, sizeof(MedicalRecord), 1, file);
        current = current->next;
    }
    fclose(file);
}

// ���ز�����Ϣ���ļ�
void loadMedicalRecords() {
    FILE* file = fopen("medicalRecords.txt", "r");
    if (file == NULL) {
        return;
    }
    MedicalRecord* newRecord;
    while (1) {
        newRecord = (MedicalRecord*)malloc(sizeof(MedicalRecord));
        if (fread(newRecord, sizeof(MedicalRecord), 1, file) != 1) {
            free(newRecord);
            break;
        }
        newRecord->next = medicalRecordHead;
        medicalRecordHead = newRecord;
    }
    fclose(file);
}

// ����ҩƷ�����Ϣ���ļ�
void saveMedicineStock() {
    FILE* file = fopen("medicineStock.txt", "wb");
    if (file == NULL) {
        printf("�޷����ļ�����ҩƷ�����Ϣ��\n");
        return;
    }
    MedicineStock* current = medicineStockHead;
    while (current != NULL) {
        fwrite(current, sizeof(MedicineStock), 1, file);
        current = current->next;
    }
    fclose(file);
}

// ����ҩƷ�����Ϣ���ļ�
void loadMedicineStock() {
    FILE* file = fopen("medicineStock.txt", "r");
    if (file == NULL) {
        return;
    }
    MedicineStock* newStock;
    while (1) {
        newStock = (MedicineStock*)malloc(sizeof(MedicineStock));
        if (fread(newStock, sizeof(MedicineStock), 1, file) != 1) {
            free(newStock);
            break;
        }
        newStock->next = medicineStockHead;
        medicineStockHead = newStock;
    }
    fclose(file);
}

// ����ҩƷ������Ϣ���ļ�
void saveMedicineSales() {
    FILE* file = fopen("medicineSales.txt", "wb");
    if (file == NULL) {
        printf("�޷����ļ�����ҩƷ������Ϣ��\n");
        return;
    }
    MedicineSale* current = medicineSaleHead;
    while (current != NULL) {
        fwrite(current, sizeof(MedicineSale), 1, file);
        current = current->next;
    }
    fclose(file);
}

// ����ҩƷ������Ϣ���ļ�
void loadMedicineSales() {
    FILE* file = fopen("medicineSales.txt", "r");
    if (file == NULL) {
        return;
    }
    MedicineSale* newSale;
    while (1) {
        newSale = (MedicineSale*)malloc(sizeof(MedicineSale));
        if (fread(newSale, sizeof(MedicineSale), 1, file) != 1) {
            free(newSale);
            break;
        }
        newSale->next = medicineSaleHead;
        medicineSaleHead = newSale;
    }
    fclose(file);
}

// ������Ϣ������
void managePatientInfo() {
    int choice;
    while (1) {
        clearScreen();
        printf("\n������Ϣ����˵�:\n");
        printf("1. ¼�뻼����Ϣ\n");
        printf("2. ��ѯ������Ϣ��������\n");
        printf("3. ��ѯ������Ϣ�����֤��\n");
        printf("4. �޸Ļ�����Ϣ\n");
        printf("0. �������˵�\n");
        printf("����������ѡ��: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1: {
            Patient* newPatient = (Patient*)malloc(sizeof(Patient));
            printf("�����뻼������: ");
            scanf("%s", newPatient->name);
            printf("�����뻼�����֤: ");
			scanf("%s", newPatient->id);
            printf("�����뻼���Ա�: ");
            scanf("%s", newPatient->gender);
            printf("�����뻼������: ");
            scanf("%d", &newPatient->age);
            printf("�����뻼����ϵ��ʽ: ");
            scanf("%s", newPatient->contact);
            newPatient->next = patientHead;
            patientHead = newPatient;
            printf("������Ϣ¼��ɹ�!\n");
            savePatients();
            pause();
            break;
        }
        case 2: {
            char targetName[20];
            printf("������Ҫ��ѯ���ߵ�����: ");
            scanf("%s", targetName);

            Patient* current = patientHead;
            int found = 0;
            while (current != NULL) {
                if (strcmp(current->name, targetName) == 0) {
                    printf("��ѯ���Ļ�����Ϣ���£�\n");
                    printf("������%s���Ա�%s�����䣺%d����ϵ��ʽ��%s\n",
                        current->name, current->gender, current->age, current->contact);
                    found = 1;
                    break;
                }
                current = current->next;
            }
            if (!found) {
                printf("δ�ҵ���Ϊ %s �Ļ���\n", targetName);
            }
            pause();
            break;
        }
        case 3: {
            char targetContact[20];
            printf("������Ҫ��ѯ���ߵ����֤: ");
            scanf("%s", targetContact);

            Patient* current = patientHead;
            int found = 0;
            while (current != NULL) {
                if (strcmp(current->id, targetContact) == 0) {
                    printf("��ѯ���Ļ�����Ϣ���£�\n");
                    printf("������%s�����֤��%s���Ա�%s�����䣺%d����ϵ��ʽ��%s\n",
                        current->name, current->id, current->gender, current->age, current->contact);
                    found = 1;
                    break;
                }
                current = current->next;
            }
            if (!found) {
                printf("δ�ҵ���ϵ��ʽΪ %s �Ļ���\n", targetContact);
            }
            pause();
            break;
        }
        case 4: {
            char targetName[20];
            printf("������Ҫ�޸Ļ��ߵ�����: ");
            scanf("%s", targetName);

            Patient* current = patientHead;
            int found = 0;
            while (current != NULL) {
                if (strcmp(current->name, targetName) == 0) {
                    printf("�������µĻ����Ա�: ");
                    scanf("%s", current->gender);
                    printf("�������µĻ�������: ");
                    scanf("%d", &current->age);
                    printf("�������µĻ�����ϵ��ʽ: ");
                    scanf("%s", current->contact);
                    printf("������Ϣ�޸ĳɹ�!\n");
                    savePatients();
                    found = 1;
                    break;
                }
                current = current->next;
            }
            if (!found) {
                printf("δ�ҵ���Ϊ %s �Ļ���\n", targetName);
            }
            pause();
            break;
        }
        case 0:
            savePatients();
            return;
        default:
            printf("��Ч��ѡ������������!\n");
            pause();
        }
    }
}

// ҽ���Ű������
void manageDoctorSchedules() {
    int choice;
    while (1) {
        clearScreen();
        printf("\nҽ���Ű����˵�:\n");
        printf("1. ¼��ҽ����Ϣ\n");
        printf("2. ��ѯҽ����Ϣ��������\n");
        printf("3. ��ѯҽ����Ϣ�����ţ�\n");
        printf("4. ��ѯҽ���Űࣨ���ڣ�\n");
        printf("5. �޸�ҽ���Ű�\n");
        printf("0. �������˵�\n");
        printf("����������ѡ��: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1: {
            Doctor* newDoctor = (Doctor*)malloc(sizeof(Doctor));
            printf("������ҽ������: ");
            scanf("%s", newDoctor->name);
            printf("������ҽ������: ");
			scanf("%s", newDoctor->id);
            printf("������ҽ��רҵ: ");
            scanf("%s", newDoctor->specialty);
            printf("������ҽ��ְ��: ");
            scanf("%s", newDoctor->title);
            printf("������ҽ���Ű����: ");
            scanf("%s", newDoctor->schedule);
            newDoctor->next = doctorHead;
            doctorHead = newDoctor;
            printf("ҽ����Ϣ¼��ɹ�!\n");
            saveDoctors();
            pause();
            break;
        }
        case 2: {
            char targetName[20];
            printf("������Ҫ��ѯҽ��������: ");
            scanf("%s", targetName);

            Doctor* current = doctorHead;
            int found = 0;
            while (current != NULL) {
                if (strcmp(current->name, targetName) == 0) {
                    printf("��ѯ����ҽ����Ϣ���£�\n");
                    printf("������%s��רҵ��%s��ְ�ƣ�%s���Ű������%s\n",
                        current->name, current->specialty, current->title, current->schedule);
                    found = 1;
                    break;
                }
                current = current->next;
            }
            if (!found) {
                printf("δ�ҵ���Ϊ %s ��ҽ��\n", targetName);
            }
            pause();
            break;
        }
         case 3: {
		            char targetDate[20];
		            printf("������Ҫ��ѯ�Ĺ���: ");
		            scanf("%s", targetDate);
		
		            Doctor* current = doctorHead;
		            int found = 0;
		            while (current != NULL) {
		                if (strstr(current->id, targetDate) != NULL) {
		                    printf("��ѯ����ҽ����Ϣ���£�\n");
		                    printf("������%s�����ţ�%s��רҵ��%s��ְ�ƣ�%s���Ű������%s\n",
		                        current->name,current->id,current->specialty, current->title, current->schedule);
		                    found = 1;
		                }
		                current = current->next;
		            }
		            if (!found) {
		                printf("δ�ҵ��� %s �Ű��ҽ��\n", targetDate);
		            }
		            pause();
		            break;
		        }
        case 4: {
            char targetDate[20];
            printf("������Ҫ��ѯ���Ű�����: ");
            scanf("%s", targetDate);

            Doctor* current = doctorHead;
            int found = 0;
            while (current != NULL) {
                if (strstr(current->schedule, targetDate) != NULL) {
                    printf("��ѯ����ҽ����Ϣ���£�\n");
                    printf("������%s��רҵ��%s��ְ�ƣ�%s���Ű������%s\n",
                        current->name, current->specialty, current->title, current->schedule);
                    found = 1;
                }
                current = current->next;
            }
            if (!found) {
                printf("δ�ҵ��� %s �Ű��ҽ��\n", targetDate);
            }
            pause();
            break;
        }
        case 5: {
            char targetName[20];
            printf("������Ҫ�޸��Ű��ҽ������: ");
            scanf("%s", targetName);

            Doctor* current = doctorHead;
            int found = 0;
            while (current != NULL) {
                if (strcmp(current->name, targetName) == 0) {
                    printf("�������µ�ҽ���Ű����: ");
                    scanf("%s", current->schedule);
                    printf("ҽ���Ű��޸ĳɹ�!\n");
                    saveDoctors();
                    found = 1;
                    break;
                }
                current = current->next;
            }
            if (!found) {
                printf("δ�ҵ���Ϊ %s ��ҽ��\n", targetName);
            }
            pause();
            break;
        }
        case 0:
            saveDoctors();
            return;
        default:
            printf("��Ч��ѡ������������!\n");
            pause();
        }
    }
}

// �ҺŹ�����
void manageAppointments() {
    int choice;
    while (1) {
        clearScreen();
        printf("\n�ҺŹ���˵�:\n");
        printf("1. ���߹Һ�\n");
        printf("2. �����˺�\n");
        printf("3. ��ѯ�Һ���Ϣ\n");
        printf("0. �������˵�\n");
        printf("����������ѡ��: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1: {
            Appointment* newAppointment = (Appointment*)malloc(sizeof(Appointment));
            printf("�����뻼������: ");
            scanf("%s", newAppointment->patientName);
            printf("������ҽ������: ");
            scanf("%s", newAppointment->doctorName);
            printf("������Һ�����: ");
            scanf("%s", newAppointment->date);
            printf("������Һŷ���: ");
            scanf("%f", &newAppointment->fee);
            newAppointment->next = appointmentHead;
            appointmentHead = newAppointment;
            printf("�Һųɹ�!\n");
            saveAppointments();
            pause();
            break;
        }
        case 2: {
            char targetPatientName[20];
            printf("������Ҫ�˺ŵĻ�������: ");
            scanf("%s", targetPatientName);

            Appointment* current = appointmentHead;
            Appointment* prev = NULL;
            int found = 0;
            while (current != NULL) {
                if (strcmp(current->patientName, targetPatientName) == 0) {
                    if (prev == NULL) {
                        appointmentHead = current->next;
                    }
                    else {
                        prev->next = current->next;
                    }
                    free(current);
                    printf("�˺ųɹ�!\n");
                    saveAppointments();
                    found = 1;
                    break;
                }
                prev = current;
                current = current->next;
            }
            if (!found) {
                printf("δ�ҵ���Ϊ %s �ĹҺ���Ϣ\n", targetPatientName);
            }
            pause();
            break;
        }
        case 3: {
            char targetDate[20];
            printf("������Ҫ��ѯ�ĹҺ�����: ");
            scanf("%s", targetDate);

            Appointment* current = appointmentHead;
            int found = 0;
            while (current != NULL) {
                if (strcmp(current->date, targetDate) == 0) {
                    printf("��ѯ���ĹҺ���Ϣ���£�\n");
                    printf("����������%s��ҽ��������%s���Һ����ڣ�%s���Һŷ��ã�%.2f\n",
                        current->patientName, current->doctorName, current->date, current->fee);
                    found = 1;
                }
                current = current->next;
            }
            if (!found) {
                printf("δ�ҵ��� %s �ĹҺ���Ϣ\n", targetDate);
            }
            pause();
            break;
        }
        case 4: {
		             char targetPatientName[50];
					    printf("������Ҫ��ѯ�Ļ�������: ");
					    scanf("%s", targetPatientName);
					
					    Appointment* current = appointmentHead;
					    int found = 0;
					    while (current != NULL) {
					        if (strcmp(current->patientName, targetPatientName) == 0) {
					            printf("��ѯ���ĹҺ���Ϣ���£�\n");
					            printf("��������: %s, ҽ������: %s, �Һ�����: %s, �Һŷ���: %.2f\n", 
					                   current->patientName, current->doctorName, current->date, current->fee);
					            found = 1;
					        }
					        current = current->next;
					    }
					    if (!found) {
					        printf("δ�ҵ���Ϊ %s �ĹҺ���Ϣ\n", targetPatientName);
					    }
					    pause();
					    break;
		        }
        case 0:
            saveAppointments();
            return;
        default:
            printf("��Ч��ѡ������������!\n");
            pause();
        }
    }
}

// ����������
void manageMedicalRecords() {
    int choice;
    while (1) {
        clearScreen();
        printf("\n��������˵�:\n");
        printf("1. ¼�벡����Ϣ\n");
        printf("2. ��ѯ������Ϣ\n");
        printf("3. �޸Ĳ�����Ϣ\n");
        printf("0. �������˵�\n");
        printf("����������ѡ��: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1: {
            MedicalRecord* newRecord = (MedicalRecord*)malloc(sizeof(MedicalRecord));
            printf("�����벡�����: ");
            scanf("%d", &newRecord->recordId);
            printf("�����뻼������: ");
            scanf("%s", newRecord->patientName);
            printf("�����벡������: ");
            scanf("%s", newRecord->content);
            newRecord->next = medicalRecordHead;
            medicalRecordHead = newRecord;
            printf("������Ϣ¼��ɹ�!\n");
            saveMedicalRecords();
            pause();
            break;
        }
        case 2: {
            int targetRecordId;
            printf("������Ҫ��ѯ�Ĳ������: ");
            scanf("%d", &targetRecordId);

            MedicalRecord* current = medicalRecordHead;
            int found = 0;
            while (current != NULL) {
                if (current->recordId == targetRecordId) {
                    printf("��ѯ���Ĳ�����Ϣ���£�\n");
                    printf("������ţ�%d������������%s���������ݣ�%s\n",
                        current->recordId, current->patientName, current->content);
                    found = 1;
                    break;
                }
                current = current->next;
            }
            if (!found) {
                printf("δ�ҵ����Ϊ %d �Ĳ���\n", targetRecordId);
            }
            pause();
            break;
        }
        case 3: {
            int targetRecordId;
            printf("������Ҫ�޸ĵĲ������: ");
            scanf("%d", &targetRecordId);

            MedicalRecord* current = medicalRecordHead;
            int found = 0;
            while (current != NULL) {
                if (current->recordId == targetRecordId) {
                    printf("�������µĲ�������: ");
                    scanf("%s", current->content);
                    printf("������Ϣ�޸ĳɹ�!\n");
                    saveMedicalRecords();
                    found = 1;
                    break;
                }
                current = current->next;
            }
            if (!found) {
                printf("δ�ҵ����Ϊ %d �Ĳ���\n", targetRecordId);
            }
            pause();
            break;
        }
        case 0:
            saveMedicalRecords();
            return;
        default:
            printf("��Ч��ѡ������������!\n");
            pause();
        }
    }
}

// ҩƷ��������
void manageMedicineStock() {
    int choice;
    while (1) {
        clearScreen();
        printf("\nҩƷ������˵�:\n");
        printf("1. ¼��ҩƷ�����Ϣ\n");
        printf("2. ��ѯҩƷ�����Ϣ\n");
        printf("3. �޸�ҩƷ�����Ϣ\n");
        printf("0. �������˵�\n");
        printf("����������ѡ��: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1: {
            MedicineStock* newStock = (MedicineStock*)malloc(sizeof(MedicineStock));
            printf("������ҩƷ����: ");
            scanf("%s", newStock->medicineName);
            printf("������������: ");
            scanf("%d", &newStock->quantity);
            printf("����������۸�: ");
            scanf("%f", &newStock->purchasePrice);
            newStock->next = medicineStockHead;
            medicineStockHead = newStock;
            printf("ҩƷ�����Ϣ¼��ɹ�!\n");
            saveMedicineStock();
            pause();
            break;
        }
        case 2: {
            char targetMedicineName[50];
            printf("������Ҫ��ѯ��ҩƷ����: ");
            scanf("%s", targetMedicineName);

            MedicineStock* current = medicineStockHead;
            int found = 0;
            while (current != NULL) {
                if (strcmp(current->medicineName, targetMedicineName) == 0) {
                    printf("��ѯ����ҩƷ�����Ϣ���£�\n");
                    printf("ҩƷ���ƣ�%s�����������%d�������۸�%.2f\n",
                        current->medicineName, current->quantity, current->purchasePrice);
                    found = 1;
                    break;
                }
                current = current->next;
            }
            if (!found) {
                printf("δ�ҵ�����Ϊ %s ��ҩƷ\n", targetMedicineName);
            }
            pause();
            break;
        }
        case 3: {
            char targetMedicineName[50];
            printf("������Ҫ�޸Ŀ���ҩƷ����: ");
            scanf("%s", targetMedicineName);

            MedicineStock* current = medicineStockHead;
            int found = 0;
            while (current != NULL) {
                if (strcmp(current->medicineName, targetMedicineName) == 0) {
                    printf("�������µĿ������: ");
                    scanf("%d", &current->quantity);
                    printf("�������µĽ����۸�: ");
                    scanf("%f", &current->purchasePrice);
                    printf("ҩƷ�����Ϣ�޸ĳɹ�!\n");
                    saveMedicineStock();
                    found = 1;
                    break;
                }
                current = current->next;
            }
            if (!found) {
                printf("δ�ҵ�����Ϊ %s ��ҩƷ\n", targetMedicineName);
            }
            pause();
            break;
        }
        case 0:
            saveMedicineStock();
            return;
        default:
            printf("��Ч��ѡ������������!\n");
            pause();
        }
    }
}

// ҩƷ���۹�����
void manageMedicineSales() {
    int choice;
    while (1) {
        clearScreen();
        printf("\nҩƷ���۹���˵�:\n");
        printf("1. ¼��ҩƷ������Ϣ\n");
        printf("2. ¼��ҩƷ�˻���Ϣ\n");
        printf("3. ��ѯҩƷ������Ϣ�����ƣ�\n");
        printf("0. �������˵�\n");
        printf("����������ѡ��: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1: {
            MedicineSale* newSale = (MedicineSale*)malloc(sizeof(MedicineSale));
            printf("������ҩƷ����: ");
            scanf("%s", newSale->medicineName);
            printf("��������������: ");
            scanf("%d", &newSale->saleQuantity);
            printf("���������ۼ۸�: ");
            scanf("%f", &newSale->salePrice);
            printf("��������������: ");
            scanf("%s", newSale->saleDate);
            newSale->next = medicineSaleHead;
            medicineSaleHead = newSale;
            printf("ҩƷ������Ϣ¼��ɹ�!\n");
            saveMedicineSales();
            pause();
            break;
        }
        case 2: {
            char targetMedicineName[50];
            printf("������Ҫ�˻���ҩƷ����: ");
            scanf("%s", targetMedicineName);

            MedicineSale* current = medicineSaleHead;
            MedicineSale* prev = NULL;
            int found = 0;
            while (current != NULL) {
                if (strcmp(current->medicineName, targetMedicineName) == 0) {
                    if (prev == NULL) {
                        medicineSaleHead = current->next;
                    }
                    else {
                        prev->next = current->next;
                    }
                    free(current);
                    printf("ҩƷ�˻��ɹ�!\n");
                    saveMedicineSales();
                    found = 1;
                    break;
                }
                prev = current;
                current = current->next;
            }
            if (!found) {
                printf("δ�ҵ�����Ϊ %s ��ҩƷ���ۼ�¼\n", targetMedicineName);
            }
            pause();
            break;
        }
        case 3: {
            char targetMedicineName[50];
            printf("������Ҫ��ѯ��ҩƷ����: ");
            scanf("%s", targetMedicineName);

            MedicineSale* current = medicineSaleHead;
            int found = 0;
            while (current != NULL) {
                if (strcmp(current->medicineName, targetMedicineName) == 0) {
                    printf("��ѯ����ҩƷ������Ϣ���£�\n");
                    printf("ҩƷ���ƣ�%s������������%d�����ۼ۸�%.2f���������ڣ�%s\n",
                        current->medicineName, current->saleQuantity, current->salePrice, current->saleDate);
                    found = 1;
                }
                current = current->next;
            }
            if (!found) {
                printf("δ�ҵ�����Ϊ %s ��ҩƷ���ۼ�¼\n", targetMedicineName);
            }
            pause();
            break;
        }
        case 0:
            saveMedicineSales();
            return;
        default:
            printf("��Ч��ѡ������������!\n");
            pause();
        }
    }
}

// ���˵�����
void mainMenu() {
    int choice;
    while (1) {
        clearScreen();
        printf("\nҽԺ��Ϣ����ϵͳ\n");
        printf("1. ������Ϣ����\n");
        printf("2. ҽ���Ű����\n");
        printf("3. �ҺŹ���\n");
        printf("4. ��������\n");
        printf("5. ҩƷ������\n");
        printf("6. ҩƷ���۹���\n");
        printf("0. �˳�ϵͳ\n");
        printf("����������ѡ��: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            managePatientInfo();
            break;
        case 2:
            manageDoctorSchedules();
            break;
        case 3:
            manageAppointments();
            break;
        case 4:
            manageMedicalRecords();
            break;
        case 5:
            manageMedicineStock();
            break;
        case 6:
            manageMedicineSales();
            break;
        case 0:
            printf("��лʹ��ҽԺ��Ϣ����ϵͳ���ټ���\n");
            exit(0);
        default:
            printf("��Ч��ѡ������������!\n");
            pause();
        }
    }
}

// �������
int main() {
    loadPatients();
    loadDoctors();
    loadAppointments();
    loadMedicalRecords();
    loadMedicineStock();
    loadMedicineSales();
    mainMenu();
    return 0;
}

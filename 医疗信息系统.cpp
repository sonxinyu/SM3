#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义患者信息结构体
typedef struct Patient {
    char name[20];
    char id[25];
    char gender[10];
    int age;
    char contact[20];
    struct Patient* next;
} Patient;

// 定义医生信息结构体
typedef struct Doctor {
    char name[20];
    char id[25];
    char specialty[20];
    char title[20];
    char schedule[50];
    struct Doctor* next;
} Doctor;

// 定义挂号信息结构体
typedef struct Appointment {
    char patientName[20];
    char doctorName[20];
    char date[20];
    float fee;
    struct Appointment* next;
} Appointment;

// 定义病历信息结构体
typedef struct MedicalRecord {
    int recordId;
    char patientName[20];
    char content[200];
    struct MedicalRecord* next;
} MedicalRecord;

// 定义药品库存信息结构体
typedef struct MedicineStock {
    char medicineName[50];
    int quantity;
    float purchasePrice;
    struct MedicineStock* next;
} MedicineStock;

// 定义药品销售信息结构体
typedef struct MedicineSale {
    char medicineName[50];
    int saleQuantity;
    float salePrice;
    char saleDate[20];
    struct MedicineSale* next;
} MedicineSale;

// 各链表头部指针
Patient* patientHead = NULL;
Doctor* doctorHead = NULL;
Appointment* appointmentHead = NULL;
MedicalRecord* medicalRecordHead = NULL;
MedicineStock* medicineStockHead = NULL;
MedicineSale* medicineSaleHead = NULL;

// 清屏函数
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// 暂停函数
void pause() {
    printf("\n按回车键继续...");
    getchar();
    getchar();
}

// 保存患者信息到文件
void savePatients() {
    FILE* file = fopen("patients.txt", "wb");
    if (file == NULL) {
        printf("无法打开文件保存患者信息。\n");
        return;
    }
    Patient* current = patientHead;
    while (current != NULL) {
        fwrite(current, sizeof(Patient), 1, file);
        current = current->next;
    }
    fclose(file);
}

// 加载患者信息从文件
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

// 保存医生信息到文件
void saveDoctors() {
    FILE* file = fopen("doctors.txt", "wb");
    if (file == NULL) {
        printf("无法打开文件保存医生信息。\n");
        return;
    }
    Doctor* current = doctorHead;
    while (current != NULL) {
        fwrite(current, sizeof(Doctor), 1, file);
        current = current->next;
    }
    fclose(file);
}

// 加载医生信息从文件
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

// 保存挂号信息到文件
void saveAppointments() {
    FILE* file = fopen("appointments.txt", "wb");
    if (file == NULL) {
        printf("无法打开文件保存挂号信息。\n");
        return;
    }
    Appointment* current = appointmentHead;
    while (current != NULL) {
        fwrite(current, sizeof(Appointment), 1, file);
        current = current->next;
    }
    fclose(file);
}

// 加载挂号信息从文件
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

// 保存病历信息到文件
void saveMedicalRecords() {
    FILE* file = fopen("medicalRecords.txt", "wb");
    if (file == NULL) {
        printf("无法打开文件保存病历信息。\n");
        return;
    }
    MedicalRecord* current = medicalRecordHead;
    while (current != NULL) {
        fwrite(current, sizeof(MedicalRecord), 1, file);
        current = current->next;
    }
    fclose(file);
}

// 加载病历信息从文件
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

// 保存药品库存信息到文件
void saveMedicineStock() {
    FILE* file = fopen("medicineStock.txt", "wb");
    if (file == NULL) {
        printf("无法打开文件保存药品库存信息。\n");
        return;
    }
    MedicineStock* current = medicineStockHead;
    while (current != NULL) {
        fwrite(current, sizeof(MedicineStock), 1, file);
        current = current->next;
    }
    fclose(file);
}

// 加载药品库存信息从文件
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

// 保存药品销售信息到文件
void saveMedicineSales() {
    FILE* file = fopen("medicineSales.txt", "wb");
    if (file == NULL) {
        printf("无法打开文件保存药品销售信息。\n");
        return;
    }
    MedicineSale* current = medicineSaleHead;
    while (current != NULL) {
        fwrite(current, sizeof(MedicineSale), 1, file);
        current = current->next;
    }
    fclose(file);
}

// 加载药品销售信息从文件
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

// 患者信息管理函数
void managePatientInfo() {
    int choice;
    while (1) {
        clearScreen();
        printf("\n患者信息管理菜单:\n");
        printf("1. 录入患者信息\n");
        printf("2. 查询患者信息（姓名）\n");
        printf("3. 查询患者信息（身份证）\n");
        printf("4. 修改患者信息\n");
        printf("0. 返回主菜单\n");
        printf("请输入您的选择: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1: {
            Patient* newPatient = (Patient*)malloc(sizeof(Patient));
            printf("请输入患者姓名: ");
            scanf("%s", newPatient->name);
            printf("请输入患者身份证: ");
			scanf("%s", newPatient->id);
            printf("请输入患者性别: ");
            scanf("%s", newPatient->gender);
            printf("请输入患者年龄: ");
            scanf("%d", &newPatient->age);
            printf("请输入患者联系方式: ");
            scanf("%s", newPatient->contact);
            newPatient->next = patientHead;
            patientHead = newPatient;
            printf("患者信息录入成功!\n");
            savePatients();
            pause();
            break;
        }
        case 2: {
            char targetName[20];
            printf("请输入要查询患者的姓名: ");
            scanf("%s", targetName);

            Patient* current = patientHead;
            int found = 0;
            while (current != NULL) {
                if (strcmp(current->name, targetName) == 0) {
                    printf("查询到的患者信息如下：\n");
                    printf("姓名：%s，性别：%s，年龄：%d，联系方式：%s\n",
                        current->name, current->gender, current->age, current->contact);
                    found = 1;
                    break;
                }
                current = current->next;
            }
            if (!found) {
                printf("未找到名为 %s 的患者\n", targetName);
            }
            pause();
            break;
        }
        case 3: {
            char targetContact[20];
            printf("请输入要查询患者的身份证: ");
            scanf("%s", targetContact);

            Patient* current = patientHead;
            int found = 0;
            while (current != NULL) {
                if (strcmp(current->id, targetContact) == 0) {
                    printf("查询到的患者信息如下：\n");
                    printf("姓名：%s，身份证：%s，性别：%s，年龄：%d，联系方式：%s\n",
                        current->name, current->id, current->gender, current->age, current->contact);
                    found = 1;
                    break;
                }
                current = current->next;
            }
            if (!found) {
                printf("未找到联系方式为 %s 的患者\n", targetContact);
            }
            pause();
            break;
        }
        case 4: {
            char targetName[20];
            printf("请输入要修改患者的姓名: ");
            scanf("%s", targetName);

            Patient* current = patientHead;
            int found = 0;
            while (current != NULL) {
                if (strcmp(current->name, targetName) == 0) {
                    printf("请输入新的患者性别: ");
                    scanf("%s", current->gender);
                    printf("请输入新的患者年龄: ");
                    scanf("%d", &current->age);
                    printf("请输入新的患者联系方式: ");
                    scanf("%s", current->contact);
                    printf("患者信息修改成功!\n");
                    savePatients();
                    found = 1;
                    break;
                }
                current = current->next;
            }
            if (!found) {
                printf("未找到名为 %s 的患者\n", targetName);
            }
            pause();
            break;
        }
        case 0:
            savePatients();
            return;
        default:
            printf("无效的选择，请重新输入!\n");
            pause();
        }
    }
}

// 医生排班管理函数
void manageDoctorSchedules() {
    int choice;
    while (1) {
        clearScreen();
        printf("\n医生排班管理菜单:\n");
        printf("1. 录入医生信息\n");
        printf("2. 查询医生信息（姓名）\n");
        printf("3. 查询医生信息（工号）\n");
        printf("4. 查询医生排班（日期）\n");
        printf("5. 修改医生排班\n");
        printf("0. 返回主菜单\n");
        printf("请输入您的选择: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1: {
            Doctor* newDoctor = (Doctor*)malloc(sizeof(Doctor));
            printf("请输入医生姓名: ");
            scanf("%s", newDoctor->name);
            printf("请输入医生工号: ");
			scanf("%s", newDoctor->id);
            printf("请输入医生专业: ");
            scanf("%s", newDoctor->specialty);
            printf("请输入医生职称: ");
            scanf("%s", newDoctor->title);
            printf("请输入医生排班情况: ");
            scanf("%s", newDoctor->schedule);
            newDoctor->next = doctorHead;
            doctorHead = newDoctor;
            printf("医生信息录入成功!\n");
            saveDoctors();
            pause();
            break;
        }
        case 2: {
            char targetName[20];
            printf("请输入要查询医生的姓名: ");
            scanf("%s", targetName);

            Doctor* current = doctorHead;
            int found = 0;
            while (current != NULL) {
                if (strcmp(current->name, targetName) == 0) {
                    printf("查询到的医生信息如下：\n");
                    printf("姓名：%s，专业：%s，职称：%s，排班情况：%s\n",
                        current->name, current->specialty, current->title, current->schedule);
                    found = 1;
                    break;
                }
                current = current->next;
            }
            if (!found) {
                printf("未找到名为 %s 的医生\n", targetName);
            }
            pause();
            break;
        }
         case 3: {
		            char targetDate[20];
		            printf("请输入要查询的工号: ");
		            scanf("%s", targetDate);
		
		            Doctor* current = doctorHead;
		            int found = 0;
		            while (current != NULL) {
		                if (strstr(current->id, targetDate) != NULL) {
		                    printf("查询到的医生信息如下：\n");
		                    printf("姓名：%s，工号：%s，专业：%s，职称：%s，排班情况：%s\n",
		                        current->name,current->id,current->specialty, current->title, current->schedule);
		                    found = 1;
		                }
		                current = current->next;
		            }
		            if (!found) {
		                printf("未找到在 %s 排班的医生\n", targetDate);
		            }
		            pause();
		            break;
		        }
        case 4: {
            char targetDate[20];
            printf("请输入要查询的排班日期: ");
            scanf("%s", targetDate);

            Doctor* current = doctorHead;
            int found = 0;
            while (current != NULL) {
                if (strstr(current->schedule, targetDate) != NULL) {
                    printf("查询到的医生信息如下：\n");
                    printf("姓名：%s，专业：%s，职称：%s，排班情况：%s\n",
                        current->name, current->specialty, current->title, current->schedule);
                    found = 1;
                }
                current = current->next;
            }
            if (!found) {
                printf("未找到在 %s 排班的医生\n", targetDate);
            }
            pause();
            break;
        }
        case 5: {
            char targetName[20];
            printf("请输入要修改排班的医生姓名: ");
            scanf("%s", targetName);

            Doctor* current = doctorHead;
            int found = 0;
            while (current != NULL) {
                if (strcmp(current->name, targetName) == 0) {
                    printf("请输入新的医生排班情况: ");
                    scanf("%s", current->schedule);
                    printf("医生排班修改成功!\n");
                    saveDoctors();
                    found = 1;
                    break;
                }
                current = current->next;
            }
            if (!found) {
                printf("未找到名为 %s 的医生\n", targetName);
            }
            pause();
            break;
        }
        case 0:
            saveDoctors();
            return;
        default:
            printf("无效的选择，请重新输入!\n");
            pause();
        }
    }
}

// 挂号管理函数
void manageAppointments() {
    int choice;
    while (1) {
        clearScreen();
        printf("\n挂号管理菜单:\n");
        printf("1. 患者挂号\n");
        printf("2. 患者退号\n");
        printf("3. 查询挂号信息\n");
        printf("0. 返回主菜单\n");
        printf("请输入您的选择: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1: {
            Appointment* newAppointment = (Appointment*)malloc(sizeof(Appointment));
            printf("请输入患者姓名: ");
            scanf("%s", newAppointment->patientName);
            printf("请输入医生姓名: ");
            scanf("%s", newAppointment->doctorName);
            printf("请输入挂号日期: ");
            scanf("%s", newAppointment->date);
            printf("请输入挂号费用: ");
            scanf("%f", &newAppointment->fee);
            newAppointment->next = appointmentHead;
            appointmentHead = newAppointment;
            printf("挂号成功!\n");
            saveAppointments();
            pause();
            break;
        }
        case 2: {
            char targetPatientName[20];
            printf("请输入要退号的患者姓名: ");
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
                    printf("退号成功!\n");
                    saveAppointments();
                    found = 1;
                    break;
                }
                prev = current;
                current = current->next;
            }
            if (!found) {
                printf("未找到名为 %s 的挂号信息\n", targetPatientName);
            }
            pause();
            break;
        }
        case 3: {
            char targetDate[20];
            printf("请输入要查询的挂号日期: ");
            scanf("%s", targetDate);

            Appointment* current = appointmentHead;
            int found = 0;
            while (current != NULL) {
                if (strcmp(current->date, targetDate) == 0) {
                    printf("查询到的挂号信息如下：\n");
                    printf("患者姓名：%s，医生姓名：%s，挂号日期：%s，挂号费用：%.2f\n",
                        current->patientName, current->doctorName, current->date, current->fee);
                    found = 1;
                }
                current = current->next;
            }
            if (!found) {
                printf("未找到在 %s 的挂号信息\n", targetDate);
            }
            pause();
            break;
        }
        case 4: {
		             char targetPatientName[50];
					    printf("请输入要查询的患者名字: ");
					    scanf("%s", targetPatientName);
					
					    Appointment* current = appointmentHead;
					    int found = 0;
					    while (current != NULL) {
					        if (strcmp(current->patientName, targetPatientName) == 0) {
					            printf("查询到的挂号信息如下：\n");
					            printf("患者姓名: %s, 医生姓名: %s, 挂号日期: %s, 挂号费用: %.2f\n", 
					                   current->patientName, current->doctorName, current->date, current->fee);
					            found = 1;
					        }
					        current = current->next;
					    }
					    if (!found) {
					        printf("未找到名为 %s 的挂号信息\n", targetPatientName);
					    }
					    pause();
					    break;
		        }
        case 0:
            saveAppointments();
            return;
        default:
            printf("无效的选择，请重新输入!\n");
            pause();
        }
    }
}

// 病历管理函数
void manageMedicalRecords() {
    int choice;
    while (1) {
        clearScreen();
        printf("\n病历管理菜单:\n");
        printf("1. 录入病历信息\n");
        printf("2. 查询病历信息\n");
        printf("3. 修改病历信息\n");
        printf("0. 返回主菜单\n");
        printf("请输入您的选择: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1: {
            MedicalRecord* newRecord = (MedicalRecord*)malloc(sizeof(MedicalRecord));
            printf("请输入病历编号: ");
            scanf("%d", &newRecord->recordId);
            printf("请输入患者姓名: ");
            scanf("%s", newRecord->patientName);
            printf("请输入病历内容: ");
            scanf("%s", newRecord->content);
            newRecord->next = medicalRecordHead;
            medicalRecordHead = newRecord;
            printf("病历信息录入成功!\n");
            saveMedicalRecords();
            pause();
            break;
        }
        case 2: {
            int targetRecordId;
            printf("请输入要查询的病历编号: ");
            scanf("%d", &targetRecordId);

            MedicalRecord* current = medicalRecordHead;
            int found = 0;
            while (current != NULL) {
                if (current->recordId == targetRecordId) {
                    printf("查询到的病历信息如下：\n");
                    printf("病历编号：%d，患者姓名：%s，病历内容：%s\n",
                        current->recordId, current->patientName, current->content);
                    found = 1;
                    break;
                }
                current = current->next;
            }
            if (!found) {
                printf("未找到编号为 %d 的病历\n", targetRecordId);
            }
            pause();
            break;
        }
        case 3: {
            int targetRecordId;
            printf("请输入要修改的病历编号: ");
            scanf("%d", &targetRecordId);

            MedicalRecord* current = medicalRecordHead;
            int found = 0;
            while (current != NULL) {
                if (current->recordId == targetRecordId) {
                    printf("请输入新的病历内容: ");
                    scanf("%s", current->content);
                    printf("病历信息修改成功!\n");
                    saveMedicalRecords();
                    found = 1;
                    break;
                }
                current = current->next;
            }
            if (!found) {
                printf("未找到编号为 %d 的病历\n", targetRecordId);
            }
            pause();
            break;
        }
        case 0:
            saveMedicalRecords();
            return;
        default:
            printf("无效的选择，请重新输入!\n");
            pause();
        }
    }
}

// 药品库存管理函数
void manageMedicineStock() {
    int choice;
    while (1) {
        clearScreen();
        printf("\n药品库存管理菜单:\n");
        printf("1. 录入药品库存信息\n");
        printf("2. 查询药品库存信息\n");
        printf("3. 修改药品库存信息\n");
        printf("0. 返回主菜单\n");
        printf("请输入您的选择: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1: {
            MedicineStock* newStock = (MedicineStock*)malloc(sizeof(MedicineStock));
            printf("请输入药品名称: ");
            scanf("%s", newStock->medicineName);
            printf("请输入库存数量: ");
            scanf("%d", &newStock->quantity);
            printf("请输入进货价格: ");
            scanf("%f", &newStock->purchasePrice);
            newStock->next = medicineStockHead;
            medicineStockHead = newStock;
            printf("药品库存信息录入成功!\n");
            saveMedicineStock();
            pause();
            break;
        }
        case 2: {
            char targetMedicineName[50];
            printf("请输入要查询的药品名称: ");
            scanf("%s", targetMedicineName);

            MedicineStock* current = medicineStockHead;
            int found = 0;
            while (current != NULL) {
                if (strcmp(current->medicineName, targetMedicineName) == 0) {
                    printf("查询到的药品库存信息如下：\n");
                    printf("药品名称：%s，库存数量：%d，进货价格：%.2f\n",
                        current->medicineName, current->quantity, current->purchasePrice);
                    found = 1;
                    break;
                }
                current = current->next;
            }
            if (!found) {
                printf("未找到名称为 %s 的药品\n", targetMedicineName);
            }
            pause();
            break;
        }
        case 3: {
            char targetMedicineName[50];
            printf("请输入要修改库存的药品名称: ");
            scanf("%s", targetMedicineName);

            MedicineStock* current = medicineStockHead;
            int found = 0;
            while (current != NULL) {
                if (strcmp(current->medicineName, targetMedicineName) == 0) {
                    printf("请输入新的库存数量: ");
                    scanf("%d", &current->quantity);
                    printf("请输入新的进货价格: ");
                    scanf("%f", &current->purchasePrice);
                    printf("药品库存信息修改成功!\n");
                    saveMedicineStock();
                    found = 1;
                    break;
                }
                current = current->next;
            }
            if (!found) {
                printf("未找到名称为 %s 的药品\n", targetMedicineName);
            }
            pause();
            break;
        }
        case 0:
            saveMedicineStock();
            return;
        default:
            printf("无效的选择，请重新输入!\n");
            pause();
        }
    }
}

// 药品销售管理函数
void manageMedicineSales() {
    int choice;
    while (1) {
        clearScreen();
        printf("\n药品销售管理菜单:\n");
        printf("1. 录入药品销售信息\n");
        printf("2. 录入药品退货信息\n");
        printf("3. 查询药品销售信息（名称）\n");
        printf("0. 返回主菜单\n");
        printf("请输入您的选择: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1: {
            MedicineSale* newSale = (MedicineSale*)malloc(sizeof(MedicineSale));
            printf("请输入药品名称: ");
            scanf("%s", newSale->medicineName);
            printf("请输入销售数量: ");
            scanf("%d", &newSale->saleQuantity);
            printf("请输入销售价格: ");
            scanf("%f", &newSale->salePrice);
            printf("请输入销售日期: ");
            scanf("%s", newSale->saleDate);
            newSale->next = medicineSaleHead;
            medicineSaleHead = newSale;
            printf("药品销售信息录入成功!\n");
            saveMedicineSales();
            pause();
            break;
        }
        case 2: {
            char targetMedicineName[50];
            printf("请输入要退货的药品名称: ");
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
                    printf("药品退货成功!\n");
                    saveMedicineSales();
                    found = 1;
                    break;
                }
                prev = current;
                current = current->next;
            }
            if (!found) {
                printf("未找到名称为 %s 的药品销售记录\n", targetMedicineName);
            }
            pause();
            break;
        }
        case 3: {
            char targetMedicineName[50];
            printf("请输入要查询的药品名称: ");
            scanf("%s", targetMedicineName);

            MedicineSale* current = medicineSaleHead;
            int found = 0;
            while (current != NULL) {
                if (strcmp(current->medicineName, targetMedicineName) == 0) {
                    printf("查询到的药品销售信息如下：\n");
                    printf("药品名称：%s，销售数量：%d，销售价格：%.2f，销售日期：%s\n",
                        current->medicineName, current->saleQuantity, current->salePrice, current->saleDate);
                    found = 1;
                }
                current = current->next;
            }
            if (!found) {
                printf("未找到名称为 %s 的药品销售记录\n", targetMedicineName);
            }
            pause();
            break;
        }
        case 0:
            saveMedicineSales();
            return;
        default:
            printf("无效的选择，请重新输入!\n");
            pause();
        }
    }
}

// 主菜单函数
void mainMenu() {
    int choice;
    while (1) {
        clearScreen();
        printf("\n医院信息管理系统\n");
        printf("1. 患者信息管理\n");
        printf("2. 医生排班管理\n");
        printf("3. 挂号管理\n");
        printf("4. 病历管理\n");
        printf("5. 药品库存管理\n");
        printf("6. 药品销售管理\n");
        printf("0. 退出系统\n");
        printf("请输入您的选择: ");
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
            printf("感谢使用医院信息管理系统，再见！\n");
            exit(0);
        default:
            printf("无效的选择，请重新输入!\n");
            pause();
        }
    }
}

// 程序入口
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

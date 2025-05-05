def start():
    print('Welcome to the Hospital Expert System!')
    print('Answer the following questions with yes or no.')
    disease = diagnose()
    print(f'You might have: {disease}')

def diagnose():
    if symptom('fever') and symptom('cough') and symptom('sore throat'):
        return 'flu'
    elif symptom('runny nose') and symptom('sneezing') and symptom('cough'):
        return 'cold'
    elif symptom('fever') and symptom('cough') and symptom('breathing difficulty'):
        return 'covid'
    else:
        return 'unknown'

def symptom(symptom_name):
    response = input(f'Do you have {symptom_name}? (yes/no): ').strip().lower()
    return response == 'yes'

if __name__ == '__main__':
    start()

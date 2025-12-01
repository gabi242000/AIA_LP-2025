package Grupa1.Java.Exceptii;

class InvalidAgeException extends Exception {
    public InvalidAgeException(String message) {
        super(message);
    }
}

class Person {
    private int age;

    public void setAge(int age) throws InvalidAgeException{
        if(age<0 || age>150){
            throw new InvalidAgeException("Varsta trebuie sa fie intre 0 si 150");
        }
        this.age = age;
        }
    }


public class Ex1 {
    public static void main(String[] args) {
        Person person = new Person();
        try {
            person.setAge(30);
        } catch (InvalidAgeException e) {
            System.out.println("Eroare: " + e.getMessage());
        }
    }
}

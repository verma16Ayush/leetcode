class Student{
    constructor(name = "Jon Doe", dept = "Civil", roll_number = "194051"){
        this.name = name
        this.dept = dept
        this.roll_number = roll_number
    }

    PrintDetails(){
        console.log(this.name);
        console.log(this.roll_number);
        console.log(this.dept);
    }
}
var ayush = new Student("ayush", "ec", "194051")
ayush.PrintDetails();

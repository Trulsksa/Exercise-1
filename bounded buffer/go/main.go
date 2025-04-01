
package main

import "fmt"
import "time"


func producer(buffer chan int){

    for i := 0; i < 10; i++ {
        time.Sleep(100 * time.Millisecond)
        fmt.Printf("[producer]: pushing %d\n", i)
        // TODO: push real value to buffer
        buffer <- i // <-- changed
    }

}

func consumer(buffer chan int){

    time.Sleep(1 * time.Second)
    for {
        value := <-buffer // <-- changed
        fmt.Printf("[consumer]: %d\n", value)
        time.Sleep(50 * time.Millisecond)
    }
    
}


func main(){
    
    buffer := make(chan int, 5)
    
    go consumer(buffer)
    go producer(buffer)
    
    select {}
}
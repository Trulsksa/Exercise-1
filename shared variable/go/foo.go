package main

import (
	"fmt"
)

func Server(incChan, decChan chan struct{}, getChan chan chan int) {
	i := 0
	for {
		select {
		case <-incChan:
			i++

		case <-decChan:
			i--

		case response := <-getChan:
			response <- i
			return
		}
	}
}

func main() {
	// Channels for the operations.
	incChan := make(chan struct{})
	decChan := make(chan struct{})
	getChan := make(chan chan int)

	doneChan := make(chan struct{}, 2)

	go Server(incChan, decChan, getChan)

	go func() {
		for j := 0; j < 1000000; j++ {
			incChan <- struct{}{}
		}
		doneChan <- struct{}{}
	}()

	go func() {
		for j := 0; j < 1000000; j++ {
			decChan <- struct{}{}
		}
		doneChan <- struct{}{}
	}()

	// Wait for both to finish sending their requests.
	<-doneChan
	<-doneChan

	// Request the final value.
	respChan := make(chan int)
	getChan <- respChan
	finalValue := <-respChan

	fmt.Println("The magic number is:", finalValue)
}

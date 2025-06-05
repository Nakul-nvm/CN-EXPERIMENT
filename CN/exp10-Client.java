import java.io.*;
import java.net.*;

class Client {
    public static void main(String[] args) {
        try (Socket socket = new Socket("localhost", 8080)) {
            BufferedReader input = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            PrintWriter output = new PrintWriter(socket.getOutputStream(), true);
            BufferedReader consoleInput = new BufferedReader(new InputStreamReader(System.in));

            String userInput;
            while (true) {
                System.out.print("Client: ");
                userInput = consoleInput.readLine();
                output.println(userInput);
                System.out.println("Server: " + input.readLine());
                if ("exit".equalsIgnoreCase(userInput)) break;
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}

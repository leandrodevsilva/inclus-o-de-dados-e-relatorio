# Waste Management System

This project is a simple Waste Management System implemented in C. It allows users to manage client information, track monthly waste quantities and costs, and generate individual and global reports. The system includes user authentication, client registration, and data management functionalities.

## Compilation

Compile the program using a C compiler (e.g., gcc).

```bash
gcc main.c -o waste_management
```

## Execution:

```bash
waste_management
```

## Example

1. Start the program and register a new user.

2. Log in with the registered credentials.

3. Register a new client with the required details.

4. Update monthly waste data for the client.

5. Generate an individual report to view the client's waste data.

6. Generate a global report to view summarized data for all clients.

## Menu Options

- Login: Log in with a username and password.

- Register User: Register a new user.

- Register Client: Register a new client.

- Update Monthly Data: Update waste data for a specific month.

- Generate Individual Report: Generate a report for a specific client.

- Generate Global Report: Generate a summary report for all clients.

- Exit: Exit the program.

## Notes

- The program supports up to 50 clients (MAX_CLIENTES).

- The system is designed for simplicity and does not include persistent storage (data is lost when the program exits).

- Error handling is minimal; ensure inputs are correct to avoid unexpected behavior.

## License

This project is made by Leandro Augusto da Silva, an open-source and available. Feel free to modify and distribute it as needed.

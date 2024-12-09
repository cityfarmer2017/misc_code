#!/bin/python3

import email
import os
import re

def parse_eml(eml_path):
    with open(eml_path, 'r', encoding='utf-8') as eml_file:
        eml_content = eml_file.read()

    msg = email.message_from_string(eml_content)
    
    sender = msg.get('From')
    recipient = msg.get('To')
    subject = msg.get('Subject')
    body = ""
    attachments = []
    links = []
    email_headers = {}

    for part in msg.walk():
        content_type = part.get_content_type()
        if content_type == 'text/plain':
            body += part.get_payload(decode=True).decode('utf-8', 'ignore')
        elif content_type == 'text/html':
            # If you want to extract HTML content, handle it accordingly
            pass
        elif content_type == 'multipart/alternative':
            # Handle alternative content types
            pass
        elif content_type.startswith('multipart'):
            # Handle multipart content types
            pass
        elif content_type.startswith('application'):
            attachment = {}
            attachment['filename'] = part.get_filename()
            attachment['content_type'] = part.get_content_type()
            attachments.append(attachment)
        elif content_type == 'message/rfc822':
            # Handle nested emails
            pass
        else:
            # Handle other content types
            pass

    # Extract links from the email body using regex
    links = re.findall(r'http[s]?://(?:[a-zA-Z]|[0-9]|[$-_@.&+]|[!*\\(\\),]|(?:%[0-9a-fA-F][0-9a-fA-F]))+', body)

    # Extract email headers
    for key, value in msg.items():
        email_headers[key] = value

    return {
        'sender': sender,
        'recipient': recipient,
        'subject': subject,
        'body': body,
        'attachments': attachments,
        'links': links,
        'email_headers': email_headers
    }

if __name__ == '__main__':
    eml_path = 'sample.eml'
    parsed_email = parse_eml(eml_path)
    print(parsed_email)
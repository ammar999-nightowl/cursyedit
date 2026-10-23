#include "Buffer.h"

Buffer::Buffer() {}

void Buffer::insertLine(string line, int n)
{
  line = remTabs(line); //conversion btw
  lines.insert(lines.begin()+n, line);

}

void Buffer::appendLine(string line)
{
  line = remTabs(line);
  lines.push_back(line);

}

void Buffer::removeLine(int n)
{
  lines.erase(lines.begin()+n);
}

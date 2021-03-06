#ifndef MERKLE_NODE_H_
#define MERKLE_NODE_H_

#include <string>
#include <memory>
#include "../sha256/sha256.hpp"


namespace bcc
{
	class merkle_node
	{
	private:
		std::shared_ptr<merkle_node> left;
		std::shared_ptr<merkle_node> right;
		std::string hash;

		merkle_node(const merkle_node & other) {}
		merkle_node & operator=(const merkle_node & other) { return * this; }

	public:
		explicit merkle_node(const std::string & value);
		merkle_node(std::shared_ptr<merkle_node> left, std::shared_ptr<merkle_node> right);
		virtual ~merkle_node();
		bool has_children() const;
		const std::string & get_hash() const;
		const std::shared_ptr<merkle_node> get_left() const;
		const std::shared_ptr<merkle_node> get_right() const;

	};
}

#endif // MERKLE_NODE_H_

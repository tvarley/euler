var assert = require('assert');
var solution031 = require('../src/euler/solution031');

describe('Solution031', function() {
  describe('answer', function() {
    it('will answer problem 031', function() {
      assert.equal(solution031.answer(), 73682);
    });
  });
});
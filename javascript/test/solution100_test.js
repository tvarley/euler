var assert = require('assert');
var solution100 = require('../src/euler/solution100');

describe('Solution100', function() {
  describe('answer', function() {
    it('will answer problem 100', function() {
      assert.equal(solution100.answer(), 756872327473);
    });
  });
});